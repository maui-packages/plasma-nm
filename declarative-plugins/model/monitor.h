/*
    Copyright 2013 Jan Grulich <jgrulich@redhat.com>

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2.1 of the License, or (at your option) version 3, or any
    later version accepted by the membership of KDE e.V. (or its
    successor approved by the membership of KDE e.V.), which shall
    act as a proxy defined in Section 6 of version 3 of the license.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this library.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef PLASMA_NM_MONITOR_H
#define PLASMA_NM_MONITOR_H

#include <NetworkManagerQt/ActiveConnection>
#include <NetworkManagerQt/AccessPoint>
#include <NetworkManagerQt/Device>
#include <NetworkManagerQt/Manager>
#include <NetworkManagerQt/VpnConnection>
#include <NetworkManagerQt/WirelessNetwork>
#include <NetworkManagerQt/WirelessDevice>

#include <ModemManagerQt/modeminterface.h>

class Monitor : public QObject
{
Q_OBJECT
public:
    explicit Monitor(QObject* parent = 0);
    virtual ~Monitor();

public Q_SLOTS:
    void init();

private Q_SLOTS:
    void availableConnectionAppeared(const QString& connection);
    void availableConnectionDisappeared(const QString& connection);
    void activeConnectionAdded(const QString& active);
    void activeConnectionRemoved(const QString& active);
    void activeConnectionStateChanged(NetworkManager::ActiveConnection::State state);
    void cablePlugged(bool plugged);
    void connectionAdded(const QString& connection);
    void connectionRemoved(const QString& connection);
    void connectionUpdated();
    void deviceAdded(const QString& device);
    void deviceRemoved(const QString& device);
    void gsmNetworkAccessTechnologyChanged(ModemManager::ModemInterface::AccessTechnology technology);
    void gsmNetworkAllowedModeChanged(ModemManager::ModemInterface::AllowedMode mode);
    void gsmNetworkSignalQualityChanged(uint signal);
    void statusChanged(NetworkManager::Status status);
    void wirelessNetworkAppeared(const QString& ssid);
    void wirelessNetworkDisappeared(const QString& ssid);
    void wirelessNetworkSignalChanged(int strength);
    void wirelessNetworkReferenceApChanged(const QString& ap);
    void wirelessEnabled(bool enabled);
Q_SIGNALS:
    void activeConnectionStateChanged(const QString& active, NetworkManager::ActiveConnection::State state);
    void addActiveConnection(const QString& active);
    void addConnection(const QString& connection, const QString& device);
    void addVpnConnection(const QString& connection);
    void addWirelessNetwork(const QString& network, const QString& device);
    void connectionUpdated(const QString& connection);
    void modemAccessTechnologyChanged(const QString& modem);
    void modemAllowedModeChanged(const QString& modem);
    void modemSignalQualityChanged(const QString& modem);
    void removeActiveConnection(const QString& active);
    void removeConnectionsByDevice(const QString& udi);
    void removeConnection(const QString& connection);
    void removeVpnConnections();
    void removeWirelessNetwork(const QString& ssid, const QString& device);
    void removeWirelessNetworks();
    void vpnConnectionStateChanged(const QString& vpn, NetworkManager::VpnConnection::State state);
    void wirelessNetworkSignalChanged(const QString& ssid, int signal);
    void wirelessNetworkAccessPointChanged(const QString& ssid, const QString& ap);

private:
    void addAvailableConnectionsForDevice(const NetworkManager::Device::Ptr& device);
    void addDevice(const NetworkManager::Device::Ptr& device);
};

#endif // PLASMA_NM_MONITOR_H
