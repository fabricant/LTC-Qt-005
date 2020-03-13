#include "bankaccount.h"

BankAccount::BankAccount(Bank *parentBank) : QObject(parentBank)
{
    m_balance = 0;
    connect(this, &BankAccount::balanceChanged, parentBank, &Bank::updateTotalBalance);
    // TODO: connect Bank slots to BankAccount signals
}

long BankAccount::balance() const
{
    return m_balance;
}

void BankAccount::setBalance(long newBalance)
{
    m_balance = newBalance;
    emit balanceChanged(newBalance);
    // TODO: add here signal emition
}

void BankAccount::deposit(long amount)
{
    // TODO: implement this function
    m_balance += amount;
    emit balanceChanged(m_balance);

}

void BankAccount::withdraw(long amount)
{
    // TODO: implement this function
    if (m_balance >= amount) {
        m_balance -= amount;
        emit balanceChanged(m_balance);

    }
}
