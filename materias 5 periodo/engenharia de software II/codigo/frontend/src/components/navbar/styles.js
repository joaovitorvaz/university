/* eslint-disable spaced-comment */
import styled from 'styled-components';
import {Link} from 'react-router-dom';

//navbar.js
export const Nav = styled.nav`
  position: fixed;
  width: 100%;
  height: auto;
  padding: 0 20px;
  display: flex;
  justify-content: space-between;
  background: rgb(36,0,70);
  background: -moz-linear-gradient(180deg, rgba(36,0,70,1) 0%, rgba(16,0,43,1) 100%);
  background: -webkit-linear-gradient(180deg, rgba(36,0,70,1) 0%, rgba(16,0,43,1) 100%);
  background: linear-gradient(180deg, rgba(36,0,70,1) 0%, rgba(16,0,43,1) 100%);
  filter: progid:DXImageTransform.Microsoft.gradient(startColorstr="#240046",endColorstr="#10002b",GradientType=1);
  z-index: 9999;
  padding-left: 10%;
  padding-right: 10%; 
`;

export const Logo = styled.div`
  display: flex;
  align-items: center;
  padding: 15px 0;
`;

export const Image = styled.img`
  width: 230px;
  height: 70px;
`;

//burguer.js
export const StyledBurger = styled.div`
  width: 2rem;
  height: 2rem;
  position: fixed;
  top: 23.5px;
  right: 25px;
  z-index: 20;
  display: none;

  @media (max-width: 850px) {
    display: flex;
    justify-content: space-around;
    flex-flow: column nowrap;
  }

  div {
    width: 2rem;
    height: 0.25rem;
    background-color: ${({ open, theme }) =>
      open ? theme.colors.primary : theme.colors.light};
    border-radius: 10px;
    transform-origin: 1px;
    transition: all 0.3s linear;

    &:nth-child(1) {
      transform: ${({ open }) => (open ? 'rotate(45deg)' : 'rotate(0)')};
    }

    &:nth-child(2) {
      transform: ${({ open }) => (open ? 'translateX(100%)' : 'translateX(0)')};
      opacity: ${({ open }) => (open ? 0 : 1)};
    }

    &:nth-child(3) {
      transform: ${({ open }) => (open ? 'rotate(-45deg)' : 'rotate(0)')};
    }
  }
`;

//rightNav.js
export const Ul = styled.ul`
  list-style: none;
  display: flex;
  flex-flow: row nowrap;
  align-items: center;

  li {
    display: flex;
    flex-direction: column;
    width: 90%;
    padding: 18px 10px;
  }

  @media (max-width: 850px) {
    flex-flow: column nowrap;
    align-items: flex-start;
    background-color: ${({ theme }) => theme.colors.background};
    position: fixed;
    margin-top: 0px;
    transform: ${({ open }) => (open ? 'translateX(0)' : 'translateX(100%)')};
    top: 0;
    right: 0;
    height: 100vh;
    width: 95%;
    padding-top: 3.5rem;
    transition: transform 0.3s ease-in-out;

    li {
      color: ${({ theme }) => theme.colors.light};

      &:nth-child(1) {
        margin-top: 25px;
      }
    }
  }
`;

export const Redirect = styled(Link)`
  color: ${({ theme }) => theme.colors.light};
  font-size: 22px;

  :hover {
    color: ${({ theme }) => theme.colors.third};
    opacity: 0.9;
    transition: 0.3s;
  }
`;

export const Line = styled.canvas`
  visibility: hidden;
  width: 0px;
  height: 0px;

  @media (max-width: 850px) {
    visibility: visible;
    align-self: flex-start;
    width: 98%;
    height: 1px;
    margin-top: 2px;
    background-color: ${({ theme }) => theme.colors.primary};
  }
`;
