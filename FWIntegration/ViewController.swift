//
//  ViewController.swift
//  FWIntegration
//
//  Created by RAC INFRA RENTAL LLP on 11/03/21.
//

import UIKit
//import Swarmin;
import SwarminFramework;

class ViewController: UIViewController {

    override func viewDidLoad() {
        let swarminControl = CoreWrapper();
        CoreWrapper.runSwarminNode("test");
        super.viewDidLoad()
        // Do any additional setup after loading the view.
    }


}

