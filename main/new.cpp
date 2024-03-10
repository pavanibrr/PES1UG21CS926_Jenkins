pipeline {
    agent any 

    stages {
        stage('Build') {
            steps {
                sh 'g++ -o myExecutable main/new.cpp'
            }
        }
        stage('Test') {
            steps {
                sh './myExecutable'
            }
        }
        stage('Deploy') {
            steps {
                echo 'Deployment completed successfully'
            }
        }
    }

    post {
        success {
            echo 'Pipeline succeeded'
        }
        failure {
            echo 'Pipeline failed'
        }
    }
}
