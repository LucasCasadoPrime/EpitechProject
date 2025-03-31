FROM jenkins/jenkins:lts
ENV JAVA_OPTS "-Djenkins.install.runSetupWizard=false -Dpermissive-script-security.enabled=true"
COPY plugins.txt /usr/share/jenkins/ref/plugins.txt
RUN /usr/local/bin/install-plugins.sh < /usr/share/jenkins/ref/plugins.txt
RUN for f in /usr/share/jenkins/ref/plugins/*.jpi; do mv $f $f.override ; done
USER root
RUN apt-get update
RUN apt-get install -y build-essential libcriterion-dev