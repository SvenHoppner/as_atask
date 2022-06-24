AS's Analysis Task
==================

Legacy code.

## Requirements

* A proper **AliPhysics** and **AliRoot** environment, with **ROOT v6** onwards.

* A valid **alien-token**

## Usage

* To use interactively on a single run, you need the following files in the directory:

  * `AliESDs.root`

  * `TRD.Digits.root`

  Then, you must execute:

  ```
  aliroot runGridESD_make_tracklets.C
  ```

* To use interactively but sequential runs

```
./analyze.sh <channel>
```

* To send jobs to the farm (STILL PENDING)

