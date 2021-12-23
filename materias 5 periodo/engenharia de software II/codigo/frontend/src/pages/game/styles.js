import styled from 'styled-components';
import {Link} from 'react-router-dom';
import { ContainerBox } from '../../components/global';

export const Redirect = styled(Link)`
  width: 50%;
`;

export const ContainerGamePage = styled(ContainerBox)`
  background-color: ${({ theme }) => theme.colors.background};
  min-height: 100vh;
  flex-direction: column;
  justify-content: top;
  align-items: center;
  padding-left: 10%;
  padding-right: 10%;
`;


export const GameData = styled.div`
  width: 100%;
  display: flex;
  flex-direction: row;
  justify-content: center;
  align-items: flex-start;

  @media screen and (max-width:850px){
    flex-direction: column;
    align-items: center;
  }
`;

export const InformationSection = styled.div`
  width: 50%;
  height: auto;
  display: flex;
  flex-direction: column;

  p {
    text-align: justify;
    font-size: 16px;
    color: white;
  }
  @media screen and (max-width:850px){
    p {
      width: 100%;
      text-align: justify;
      font-size: 16px;
      color: white;
    }
  }
`;

export const GoBack = styled.div`
  width: 100%;
  height: auto;
  display: flex;

  p {
    font-size: 20px;
    color: ${({ theme }) => theme.colors.light};
  }
`;

export const ImageSection = styled.div`
  width: 50%;
  display: flex;
  justify-content: flex-start;
  align-self: center;
  
  @media screen and (max-width:850px){
    justify-content: center;
    width: 100%;
  }
`;

export const Image = styled.img`
  width: 320px;
  height: 390px;
  size: cover;
  repeat: no-repeat, repeat;
`;

export const GameName = styled.h2`
  padding-left: 10px;
  padding-right: 10px;
  margin-right: auto;
  font-weight: normal;
  font-size: 2.0rem;
  background-color: ${({ theme }) => theme.colors.light};  
  border-radius: 10px;
  text-align: start;
  color: ${({ theme }) => theme.colors.gameCard};
  margin-bottom: 10px;
`;

export const Details = styled.div`
  width: 100%;
  display: flex;
  flex-direction: column;
  justify-content: flex-start;
  
  p {
    margin: 0px;

    b{
      margin-left: 5px;
      color: ${({ theme }) => theme.colors.secondary}; 
      font-weight: normal;
    }
  }
`;

export const ButtonSection = styled.div`
  width: 100%;
  display: flex;
  justify-content: center;
  margin-top: 30px;
`;

export const Block = styled.div`
  width: 100%;
  height: 100vh;
  position: absolute;
  backdrop-filter: blur(5px);
  display: flex;
  justify-content: center;
  align-items: center;

  @media screen and (max-width:850px){
    height: ${({ height }) => height};
  }
`;

export const PopUp = styled.div`
  width: 45%;
  height: 50vh;
  display: flex;
  flex-direction: column;
  justify-content: center;
  align-items: center;
  align-self: center;
  background-color: ${({ theme }) => theme.colors.background};
  border: 1px solid #6B33FF;
  border-radius: 15px;

  h3{
    color: ${({ theme }) => theme.colors.secondary};
    font-weight: normal;
    margin: 0px;
  }

  p{
    margin-bottom: 40px;
  }
`;