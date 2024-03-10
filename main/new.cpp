pipeline {
    agent any

    stages {
        stage('Build') {
            steps {
                script {
                    // Attempt compilation, and fail the build if errors occur
                    if (sh(returnStatus: true, script: 'g++ -o myExecutable main/new.cpp') != 0) {
                        error('Compilation failed')
                    } 
                }
            }
        }

        stage('Test') {
            steps {
                script {
                    // Execute the compiled program
                    sh './myExecutable'
                }
            }
        }

        stage('Deploy') {
            steps {
                script {
                    // Replace with your actual deployment steps, e.g.,
                    // sh 'scp myExecutable user@targetserver:/deployment/path'

                    // Placeholder for now
                    echo 'Deployment steps would go here' 
                }
            }
        }
    }

    post {
        success {
            echo 'Pipeline succeeded'
            // Add success notifications if desired (email, Slack, etc.)
        }

        failure {
            echo 'Pipeline failed'
            // Add failure notifications if desired (email, Slack, etc.)
        }
    }
}
