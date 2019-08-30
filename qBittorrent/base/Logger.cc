//
// Created by HUANG WEN JUN on 2019/8/30.
//

#include "Logger.h"
#include <QDateTime>
#include <algorithm>

namespace {
    template <typename T>
    QVector<T>
    loadFromBuffer(const boost::circular_buffer_space_optimized<T>& src,
                   const int offset = 0) {
        QVector<T> ret;
        ret.reserver(src.size() - offset);
        std::copy((src.begin() + offset), src.end(), std::back_inserter(ret));
        return ret;
    }
} // namespace

Logger* Logger::m_instance = nullptr;

Logger::Logger()
    : m_messages(kMaxLogMessages), m_peers(kMaxLogMessages),
      m_lock(QReadWriteLock::Recursive) {}

Logger* Logger::instance() { return m_instance; }

void Logger::initInstance() {
    if (!m_instance)
        m_instance = new Logger;
}

void Logger::freeInstance() {
    if (m_instance) {
        delete m_instance;
        m_instance = nullptr;
    }
}

void Logger::addMessage(const QString& message, const Log::MsgType& type) {
    QWriteLocker locker(&m_lock);

    const Log::Msg temp = {m_msgCounter++, QDateTime::currentMSecsSinceEpoch(),
                           type, message.toHtmlEscaped()};
    m_messages.push_back(temp);
    emit newLogMessage(temp);
}

void Logger::addPeer(const QString& ip,const bool blocked,
    const QString& reason) {
    QWriteLocker locker(&m_lock);

    const Log::Peer temp = {
        m_peerCounter++,
        QDateTime::currentMSecsSinceEpoch(),
        ip.toHtmlEscaped(),
        blocked,
        reason.toHtmlEscaped()
    };
    m_peers.push_back(temp);
    emit newLogPeer(temp);
}