/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-cola <ede-cola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 12:40:29 by ede-cola          #+#    #+#             */
/*   Updated: 2024/06/13 12:33:07 by ede-cola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>

class Contact
{
	private:
		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		std::string	phone_number;
		std::string	darkest_secret;

	public:
		Contact(void);
		~Contact();
		void setFirstname(const std::string firstName);
		void setLastname(const std::string lastName);
		void setNickname(const std::string nickName);
		void setPhoneNumber(const std::string phoneNUmber);
		void setDarkestSecret(const std::string darkestSecret);

		std::string getFirstname(void) const;
		std::string getLastname(void) const;
		std::string getNickname(void) const;
		std::string getPhoneNumber(void) const;
		std::string getDarkestSecret(void) const;

};

#endif