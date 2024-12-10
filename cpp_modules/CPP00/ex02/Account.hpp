/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamuel <dsamuel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:06:09 by dsamuel           #+#    #+#             */
/*   Updated: 2024/12/10 14:14:47 by dsamuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __ACCOUNT_HPP__
#define __ACCOUNT_HPP__

class Account {
    
public:

    typedef Account     t;
    
    static int          getNbAccounts( void );
    static int          getTotalAmount( void );
    static int          getNbDeposits( void );
    static int          getNbWithdrawals( void );
    static void         displayAccountsInfos( void );

    Account( int initial_deposit );
    ~Account( void );

    void                makeDeposit( int deposit );
    bool                makeWithdrawal( int withdrawal );
    int                 checkAmount( void ) const;
    void                displayStatus( void ) const;

private:
    
        static int          _nbAccounts;
        static int          _totalAmount;
        static int          _totalNbDeposits;
        static int          _totalNbWithdrawals;
        
        static void         _displayTimestamp( void );
    
        int                 _accountIndex;
        int                 _amount;
        int                 _nbDeposits;
        int                 _nbWithdrawals;

        Account( void );
};

#endif // __ACCOUNT_HPP__
