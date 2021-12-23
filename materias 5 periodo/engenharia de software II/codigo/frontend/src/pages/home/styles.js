import styled from 'styled-components';
import background from '../../assets/home/background.jpg';
import {ContainerImage} from "../../components/global";
import {Link} from 'react-router-dom';

export const ContainerHome = styled(ContainerImage)`
  min-height: 100vh;
  justify-content: center;
  align-items: center;
  background: url(${background}) fixed;
  background-size: cover;
  /* min-width: 550px; */
`;

export const CardsSection = styled.div`
  width: 70%;
  height: auto;
  display: grid;
  grid-template-columns: 1fr 1fr 1fr 1fr;
  
  @media screen and (max-width:1200px){
    grid-template-columns: 1fr 1fr 1fr;
    width: 70%;
  }
  
  @media screen and (max-width:950px){
    grid-template-columns: 1fr 1fr;
  }
  
  @media screen and (max-width:685px){
    grid-template-columns: 1fr;
    width: 50%;
  }
  
  @media screen and (max-width:550px){
    grid-template-columns: 1fr;
  }
`;
