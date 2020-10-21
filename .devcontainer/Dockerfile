
FROM gcc:latest

ARG USERNAME

ENV USERNAME=${USERNAME}
ENV HOME /home/${USERNAME}
ENV USER_UID 1000
ENV USER_GID ${USER_UID}

RUN export DEBIAN_FRONTEND=noninteractive \
  && export APT_KEY_DONT_WARN_ON_DANGEROUS_USAGE=DontWarn \
  && apt-get update \
  && apt-get -y install \
    apt-utils \
    build-essential \
    cmake \
    cppcheck \
    curl \
    dos2unix \
    file \
    git \
    jq \
    lcov \
    openssl \
    sudo \
    telnet \
    valgrind \
    vim \
  && apt-get autoremove -y \
  && apt-get clean -y \
  && rm -rf /var/lib/apt/lists/*

RUN \
  groupadd --gid ${USER_GID} ${USERNAME} \
  && useradd --uid ${USER_UID} --gid ${USERNAME} --shell /bin/bash --create-home ${USERNAME} \
  && usermod --password $(echo ${USERNAME} | openssl passwd -1 -stdin) ${USERNAME} \
  \
  && usermod -aG sudo ${USERNAME} \
  && echo ${USERNAME} ALL=\(root\) NOPASSWD:ALL > /etc/sudoers.d/${USERNAME} \
  && chmod 0440 /etc/sudoers.d/${USERNAME} \
  \
  && mkdir -p \
    ${HOME}/.vscode-server/extensions \
    ${HOME}/.vscode-server-insiders/extensions \
  && chown -R ${USERNAME}:${USERNAME} ${HOME}

ENV DOCKER_VOLUME /mnt/docker
ENV PROMPT_COMMAND 'history -a'
ENV HISTFILE ${DOCKER_VOLUME}/.bash_history

RUN mkdir ${DOCKER_VOLUME} \
  && touch ${HISTFILE} \
  && chown -R ${USERNAME}:${USERNAME} ${DOCKER_VOLUME}

WORKDIR ${HOME}
USER ${USERNAME}