
    

  

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN"
  "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="en" lang="en">
  <head>
    <meta http-equiv="content-type" content="text/html;charset=UTF-8" />
    <meta http-equiv="X-UA-Compatible" content="chrome=1">
        <title>src/server/shared/Database/Implementation/CharacterDatabase.h at master from TrinityCore's TrinityCore - GitHub</title>
    <link rel="search" type="application/opensearchdescription+xml" href="/opensearch.xml" title="GitHub" />
    <link rel="fluid-icon" href="https://github.com/fluidicon.png" title="GitHub" />

    <link href="https://assets2.github.com/stylesheets/bundle_common.css?fb793a9f8ae4a3436e27e4628ed81ae1e79a1661" media="screen" rel="stylesheet" type="text/css" />
<link href="https://assets1.github.com/stylesheets/bundle_github.css?fb793a9f8ae4a3436e27e4628ed81ae1e79a1661" media="screen" rel="stylesheet" type="text/css" />

    <script type="text/javascript">
      if (typeof console == "undefined" || typeof console.log == "undefined")
        console = { log: function() {} }
    </script>
    <script type="text/javascript" charset="utf-8">
      var GitHub = {}
      var github_user = 'Rusfighter'
      
    </script>
    <script src="https://assets0.github.com/javascripts/jquery/jquery-1.4.2.min.js?fb793a9f8ae4a3436e27e4628ed81ae1e79a1661" type="text/javascript"></script>
    <script src="https://assets0.github.com/javascripts/bundle_common.js?fb793a9f8ae4a3436e27e4628ed81ae1e79a1661" type="text/javascript"></script>
<script src="https://assets1.github.com/javascripts/bundle_github.js?fb793a9f8ae4a3436e27e4628ed81ae1e79a1661" type="text/javascript"></script>


        <script type="text/javascript" charset="utf-8">
      GitHub.spy({
        repo: "TrinityCore/TrinityCore"
      })
    </script>

    
  
    
  

  <link href="https://github.com/TrinityCore/TrinityCore/commits/master.atom" rel="alternate" title="Recent Commits to TrinityCore:master" type="application/atom+xml" />

        <meta name="description" content="" />
    <script type="text/javascript">
      GitHub.nameWithOwner = GitHub.nameWithOwner || "TrinityCore/TrinityCore";
      GitHub.currentRef = 'master';
      GitHub.commitSHA = "a74d8d6e3630c536231fd5832e87fd0b475872c3";
      GitHub.currentPath = "src/server/shared/Database/Implementation/CharacterDatabase.h";
      GitHub.masterBranch = "master";

      
    </script>
  

            <script type="text/javascript">
      var _gaq = _gaq || [];
      _gaq.push(['_setAccount', 'UA-3769691-2']);
      _gaq.push(['_trackPageview']);
      (function() {
        var ga = document.createElement('script');
        ga.src = ('https:' == document.location.protocol ? 'https://ssl' : 'http://www') + '.google-analytics.com/ga.js';
        ga.setAttribute('async', 'true');
        document.documentElement.firstChild.appendChild(ga);
      })();
    </script>

  </head>

  

  <body class="logged_in ">
    

    
      <script type="text/javascript">
        var _kmq = _kmq || [];
        function _kms(u){
          var s = document.createElement('script'); var f = document.getElementsByTagName('script')[0]; s.type = 'text/javascript'; s.async = true;
          s.src = u; f.parentNode.insertBefore(s, f);
        }
        _kms('//i.kissmetrics.com/i.js');_kms('//doug1izaerwt3.cloudfront.net/406e8bf3a2b8846ead55afb3cfaf6664523e3a54.1.js');
      </script>
    

    

    

    

    

    <div class="subnavd" id="main">
      <div id="header" class="true">
        
          <a class="logo boring" href="https://github.com/">
            <img src="/images/modules/header/logov3.png?changed" class="default" alt="github" />
            <![if !IE]>
            <img src="/images/modules/header/logov3-hover.png" class="hover" alt="github" />
            <![endif]>
          </a>
        
        
          





  
    <div class="userbox">
      <div class="avatarname">
        <a href="https://github.com/Rusfighter"><img src="https://secure.gravatar.com/avatar/c8716cd06a7d51508143ca3605a8d809?s=140&d=https%3A%2F%2Fgithub.com%2Fimages%2Fgravatars%2Fgravatar-140.png" alt="" width="20" height="20"  /></a>
        <a href="https://github.com/Rusfighter" class="name">Rusfighter</a>

        
        
          <a href="/inbox/notifications" class="unread_count notifications_count new tooltipped downwards js-notification-count" title="Unread Notifications">3</a>
        
      </div>
      <ul class="usernav">
        <li><a href="https://github.com/">Dashboard</a></li>
        <li>
          
          <a href="https://github.com/inbox">Inbox</a>
          <a href="https://github.com/inbox" class="unread_count ">0</a>
        </li>
        <li><a href="https://github.com/account">Account Settings</a></li>
                        <li><a href="/logout">Log Out</a></li>
      </ul>
    </div><!-- /.userbox -->
  


        
        <div class="topsearch">
  
    <form action="/search" id="top_search_form" method="get">
      <a href="/search" class="advanced-search tooltipped downwards" title="Advanced Search">Advanced Search</a>
      <input type="search" class="search my_repos_autocompleter" name="q" results="5" placeholder="Search&hellip;" /> <input type="submit" value="Search" class="button" />
      <input type="hidden" name="type" value="Everything" />
      <input type="hidden" name="repo" value="" />
      <input type="hidden" name="langOverride" value="" />
      <input type="hidden" name="start_value" value="1" />
    </form>
    <ul class="nav">
      <li><a href="/explore">Explore GitHub</a></li>
      <li><a href="https://gist.github.com">Gist</a></li>
      <li><a href="/blog">Blog</a></li>
      <li><a href="http://help.github.com">Help</a></li>
    </ul>
  
</div>

      </div>

      
      
        
    <div class="site">
      <div class="pagehead repohead vis-public fork  ">

      

      <div class="title-actions-bar">
        <h1>
          <a href="/TrinityCore">TrinityCore</a> / <strong><a href="https://github.com/TrinityCore/TrinityCore">TrinityCore</a></strong>
          
            <span class="fork-flag">
              
              <span class="text">forked from <a href="/TrinityDev/TrinityCore">TrinityDev/TrinityCore</a></span>
            </span>
          
          
        </h1>

        
    <ul class="actions">
      

      
        <li class="for-owner" style="display:none"><a href="https://github.com/TrinityCore/TrinityCore/admin" class="minibutton btn-admin "><span><span class="icon"></span>Admin</span></a></li>
        <li>
          <a href="/TrinityCore/TrinityCore/toggle_watch" class="minibutton btn-watch " id="watch_button" onclick="var f = document.createElement('form'); f.style.display = 'none'; this.parentNode.appendChild(f); f.method = 'POST'; f.action = this.href;var s = document.createElement('input'); s.setAttribute('type', 'hidden'); s.setAttribute('name', 'authenticity_token'); s.setAttribute('value', 'c086c05c70524d684506124042635de51e28db34'); f.appendChild(s);f.submit();return false;" style="display:none"><span><span class="icon"></span>Watch</span></a>
          <a href="/TrinityCore/TrinityCore/toggle_watch" class="minibutton btn-watch " id="unwatch_button" onclick="var f = document.createElement('form'); f.style.display = 'none'; this.parentNode.appendChild(f); f.method = 'POST'; f.action = this.href;var s = document.createElement('input'); s.setAttribute('type', 'hidden'); s.setAttribute('name', 'authenticity_token'); s.setAttribute('value', 'c086c05c70524d684506124042635de51e28db34'); f.appendChild(s);f.submit();return false;" style="display:none"><span><span class="icon"></span>Unwatch</span></a>
        </li>
        
          
            <li class="for-notforked" style="display:none"><a href="/TrinityCore/TrinityCore/fork" class="minibutton btn-fork " id="fork_button" onclick="var f = document.createElement('form'); f.style.display = 'none'; this.parentNode.appendChild(f); f.method = 'POST'; f.action = this.href;var s = document.createElement('input'); s.setAttribute('type', 'hidden'); s.setAttribute('name', 'authenticity_token'); s.setAttribute('value', 'c086c05c70524d684506124042635de51e28db34'); f.appendChild(s);f.submit();return false;"><span><span class="icon"></span>Fork</span></a></li>
            <li class="for-hasfork" style="display:none"><a href="#" class="minibutton btn-fork " id="your_fork_button"><span><span class="icon"></span>Your Fork</span></a></li>
          

          <li id='pull_request_item' class='nspr' style='display:none'><a href="/TrinityCore/TrinityCore/pull/new/master" class="minibutton btn-pull-request "><span><span class="icon"></span>Pull Request</span></a></li>
        
      
      
      <li class="repostats">
        <ul class="repo-stats">
          <li class="watchers"><a href="/TrinityCore/TrinityCore/watchers" title="Watchers" class="tooltipped downwards">240</a></li>
          <li class="forks"><a href="/TrinityCore/TrinityCore/network" title="Forks" class="tooltipped downwards">90</a></li>
        </ul>
      </li>
    </ul>

      </div>

        
  <ul class="tabs">
    <li><a href="https://github.com/TrinityCore/TrinityCore" class="selected" highlight="repo_source">Source</a></li>
    <li><a href="https://github.com/TrinityCore/TrinityCore/commits/master" highlight="repo_commits">Commits</a></li>
    <li><a href="/TrinityCore/TrinityCore/network" highlight="repo_network">Network</a></li>
    <li><a href="/TrinityCore/TrinityCore/pulls" highlight="repo_pulls">Pull Requests (0)</a></li>

    

    

    
    <li><a href="/TrinityCore/TrinityCore/graphs" highlight="repo_graphs">Graphs</a></li>

    <li class="contextswitch nochoices">
      <span class="toggle leftwards" >
        <em>Branch:</em>
        <code>master</code>
      </span>
    </li>
  </ul>

  <div style="display:none" id="pl-description"><p><em class="placeholder">click here to add a description</em></p></div>
  <div style="display:none" id="pl-homepage"><p><em class="placeholder">click here to add a homepage</em></p></div>

  <div class="subnav-bar">
  
  <ul>
    <li>
      <a href="#" class="dropdown">Switch Branches (2)</a>
      <ul>
        
          
          
            <li><a href="/TrinityCore/TrinityCore/blob/calendar/src/server/shared/Database/Implementation/CharacterDatabase.h" action="show">calendar</a></li>
          
        
          
            <li><strong>master &#x2713;</strong></li>
            
      </ul>
    </li>
    <li>
      <a href="#" class="dropdown ">Switch Tags (14)</a>
              <ul>
                      
              <li><a href="/TrinityCore/TrinityCore/blob/stable/src/server/shared/Database/Implementation/CharacterDatabase.h">stable</a></li>
            
                      
              <li><a href="/TrinityCore/TrinityCore/blob/init/src/server/shared/Database/Implementation/CharacterDatabase.h">init</a></li>
            
                      
              <li><a href="/TrinityCore/TrinityCore/blob/UP36/src/server/shared/Database/Implementation/CharacterDatabase.h">UP36</a></li>
            
                      
              <li><a href="/TrinityCore/TrinityCore/blob/UP35/src/server/shared/Database/Implementation/CharacterDatabase.h">UP35</a></li>
            
                      
              <li><a href="/TrinityCore/TrinityCore/blob/UP34/src/server/shared/Database/Implementation/CharacterDatabase.h">UP34</a></li>
            
                      
              <li><a href="/TrinityCore/TrinityCore/blob/UP33/src/server/shared/Database/Implementation/CharacterDatabase.h">UP33</a></li>
            
                      
              <li><a href="/TrinityCore/TrinityCore/blob/UP31/src/server/shared/Database/Implementation/CharacterDatabase.h">UP31</a></li>
            
                      
              <li><a href="/TrinityCore/TrinityCore/blob/UP30/src/server/shared/Database/Implementation/CharacterDatabase.h">UP30</a></li>
            
                      
              <li><a href="/TrinityCore/TrinityCore/blob/Stable/src/server/shared/Database/Implementation/CharacterDatabase.h">Stable</a></li>
            
                      
              <li><a href="/TrinityCore/TrinityCore/blob/335a-stable/src/server/shared/Database/Implementation/CharacterDatabase.h">335a-stable</a></li>
            
                      
              <li><a href="/TrinityCore/TrinityCore/blob/309-313/src/server/shared/Database/Implementation/CharacterDatabase.h">309-313</a></li>
            
                      
              <li><a href="/TrinityCore/TrinityCore/blob/3.3.5a-clientsupport/src/server/shared/Database/Implementation/CharacterDatabase.h">3.3.5a-clientsupport</a></li>
            
                      
              <li><a href="/TrinityCore/TrinityCore/blob/3.3.3a-LAST/src/server/shared/Database/Implementation/CharacterDatabase.h">3.3.3a-LAST</a></li>
            
                      
              <li><a href="/TrinityCore/TrinityCore/blob/3.3.2-last/src/server/shared/Database/Implementation/CharacterDatabase.h">3.3.2-last</a></li>
            
                  </ul>
      
    </li>
    <li>
    
    <a href="/TrinityCore/TrinityCore/branches" class="manage">Branch List</a>
    
    </li>
  </ul>
</div>

  
  
  
  
  
  



        
    <div id="repo_details" class="metabox clearfix">
      <div id="repo_details_loader" class="metabox-loader" style="display:none">Sending Request&hellip;</div>

        <a href="/TrinityCore/TrinityCore/downloads" class="download-source" id="download_button" title="Download source, tagged packages and binaries."><span class="icon"></span>Downloads</a>

      <div id="repository_desc_wrapper">
      <div id="repository_description" rel="repository_description_edit">
        
      </div>

      <div id="repository_description_edit" style="display:none;" class="inline-edit">
        <form action="/TrinityCore/TrinityCore/admin/update" method="post"><div style="margin:0;padding:0"><input name="authenticity_token" type="hidden" value="c086c05c70524d684506124042635de51e28db34" /></div>
          <input type="hidden" name="field" value="repository_description">
          <input type="text" class="textfield" name="value" value="">
          <div class="form-actions">
            <button class="minibutton"><span>Save</span></button> &nbsp; <a href="#" class="cancel">Cancel</a>
          </div>
        </form>
      </div>

      
      <div class="repository-homepage" id="repository_homepage" rel="repository_homepage_edit">
        <p><a href="http://www.TrinityCore.org" rel="nofollow">http://www.TrinityCore.org</a></p>
      </div>

      <div id="repository_homepage_edit" style="display:none;" class="inline-edit">
        <form action="/TrinityCore/TrinityCore/admin/update" method="post"><div style="margin:0;padding:0"><input name="authenticity_token" type="hidden" value="c086c05c70524d684506124042635de51e28db34" /></div>
          <input type="hidden" name="field" value="repository_homepage">
          <input type="text" class="textfield" name="value" value="http://www.TrinityCore.org">
          <div class="form-actions">
            <button class="minibutton"><span>Save</span></button> &nbsp; <a href="#" class="cancel">Cancel</a>
          </div>
        </form>
      </div>
      </div>
      <div class="rule "></div>
            <div id="url_box" class="url-box">
        <ul class="clone-urls">
          
            
            <li id="http_clone_url"><a href="https://github.com/TrinityCore/TrinityCore.git" data-permissions="Read-Only">HTTP</a></li>
            <li id="public_clone_url"><a href="git://github.com/TrinityCore/TrinityCore.git" data-permissions="Read-Only">Git Read-Only</a></li>
          
          
        </ul>
        <input type="text" spellcheck="false" id="url_field" class="url-field" />
              <span style="display:none" id="url_box_clippy"></span>
      <span id="clippy_tooltip_url_box_clippy" class="clippy-tooltip tooltipped" title="copy to clipboard">
      <object classid="clsid:d27cdb6e-ae6d-11cf-96b8-444553540000"
              width="14"
              height="14"
              class="clippy"
              id="clippy" >
      <param name="movie" value="https://assets3.github.com/flash/clippy.swf?v5"/>
      <param name="allowScriptAccess" value="always" />
      <param name="quality" value="high" />
      <param name="scale" value="noscale" />
      <param NAME="FlashVars" value="id=url_box_clippy&amp;copied=&amp;copyto=">
      <param name="bgcolor" value="#FFFFFF">
      <param name="wmode" value="opaque">
      <embed src="https://assets3.github.com/flash/clippy.swf?v5"
             width="14"
             height="14"
             name="clippy"
             quality="high"
             allowScriptAccess="always"
             type="application/x-shockwave-flash"
             pluginspage="http://www.macromedia.com/go/getflashplayer"
             FlashVars="id=url_box_clippy&amp;copied=&amp;copyto="
             bgcolor="#FFFFFF"
             wmode="opaque"
      />
      </object>
      </span>

        <p id="url_description">This URL has <strong>Read+Write</strong> access</p>
      </div>
    </div>


        

      </div><!-- /.pagehead -->

      





<script type="text/javascript">
  GitHub.downloadRepo = '/TrinityCore/TrinityCore/archives/master'
  GitHub.revType = "master"

  GitHub.controllerName = "blob"
  GitHub.actionName     = "show"
  GitHub.currentAction  = "blob#show"

  
    GitHub.hasWriteAccess = false
    GitHub.hasAdminAccess = false
    GitHub.watchingRepo = false
    GitHub.ignoredRepo = false
    GitHub.hasForkOfRepo = ""
    GitHub.hasForked = false
  

  
</script>






<div class="flash-messages"></div>


  <div id="commit">
    <div class="group">
        
  <div class="envelope commit">
    <div class="human">
      
        <div class="message"><pre><a href="/TrinityCore/TrinityCore/commit/a74d8d6e3630c536231fd5832e87fd0b475872c3">Scripts/Pit of Saron: Fixed Scourgelord Tyrannus despawning 30 seconds after death and fixed his intro being started multiple times</a> </pre></div>
      

      <div class="actor">
        <div class="gravatar">
          
          <img src="https://secure.gravatar.com/avatar/39eb7b3987ff588109d1dced1e9c6553?s=140&d=https%3A%2F%2Fgithub.com%2Fimages%2Fgravatars%2Fgravatar-140.png" alt="" width="30" height="30"  />
        </div>
        <div class="name"><a href="/Shauren">Shauren</a> <span>(author)</span></div>
        <div class="date">
          <abbr class="relatize" title="2011-01-28 13:08:17">Fri Jan 28 13:08:17 -0800 2011</abbr>
        </div>
      </div>

      

    </div>
    <div class="machine">
      <span>c</span>ommit&nbsp;&nbsp;<a href="/TrinityCore/TrinityCore/commit/a74d8d6e3630c536231fd5832e87fd0b475872c3" hotkey="c">a74d8d6e3630c536231f</a><br />
      <span>t</span>ree&nbsp;&nbsp;&nbsp;&nbsp;<a href="/TrinityCore/TrinityCore/tree/a74d8d6e3630c536231fd5832e87fd0b475872c3" hotkey="t">2cf90e5ea91297bf7f7f</a><br />
      
        <span>p</span>arent&nbsp;
        
        <a href="/TrinityCore/TrinityCore/tree/c3c2a807f024b71631af80b06f6fe5c0dcf713d7" hotkey="p">c3c2a807f024b71631af</a>
      

    </div>
  </div>

    </div>
  </div>



  
    <div id="slider">

    

      <div class="breadcrumb" data-path="src/server/shared/Database/Implementation/CharacterDatabase.h/">
        <b><a href="/TrinityCore/TrinityCore/tree/a74d8d6e3630c536231fd5832e87fd0b475872c3">TrinityCore</a></b> / <a href="/TrinityCore/TrinityCore/tree/a74d8d6e3630c536231fd5832e87fd0b475872c3/src">src</a> / <a href="/TrinityCore/TrinityCore/tree/a74d8d6e3630c536231fd5832e87fd0b475872c3/src/server">server</a> / <a href="/TrinityCore/TrinityCore/tree/a74d8d6e3630c536231fd5832e87fd0b475872c3/src/server/shared">shared</a> / <a href="/TrinityCore/TrinityCore/tree/a74d8d6e3630c536231fd5832e87fd0b475872c3/src/server/shared/Database">Database</a> / <a href="/TrinityCore/TrinityCore/tree/a74d8d6e3630c536231fd5832e87fd0b475872c3/src/server/shared/Database/Implementation">Implementation</a> / CharacterDatabase.h       <span style="display:none" id="clippy_2015">src/server/shared/Database/Implementation/CharacterDatabase.h</span>
      
      <object classid="clsid:d27cdb6e-ae6d-11cf-96b8-444553540000"
              width="110"
              height="14"
              class="clippy"
              id="clippy" >
      <param name="movie" value="https://assets3.github.com/flash/clippy.swf?v5"/>
      <param name="allowScriptAccess" value="always" />
      <param name="quality" value="high" />
      <param name="scale" value="noscale" />
      <param NAME="FlashVars" value="id=clippy_2015&amp;copied=copied!&amp;copyto=copy to clipboard">
      <param name="bgcolor" value="#FFFFFF">
      <param name="wmode" value="opaque">
      <embed src="https://assets3.github.com/flash/clippy.swf?v5"
             width="110"
             height="14"
             name="clippy"
             quality="high"
             allowScriptAccess="always"
             type="application/x-shockwave-flash"
             pluginspage="http://www.macromedia.com/go/getflashplayer"
             FlashVars="id=clippy_2015&amp;copied=copied!&amp;copyto=copy to clipboard"
             bgcolor="#FFFFFF"
             wmode="opaque"
      />
      </object>
      

      </div>

      <div class="frames">
        <div class="frame frame-center" data-path="src/server/shared/Database/Implementation/CharacterDatabase.h/">
          
            <ul class="big-actions">
              <li><a class="file-edit-link minibutton" href="/TrinityCore/TrinityCore/file-edit/master/src/server/shared/Database/Implementation/CharacterDatabase.h"><span>Edit this file</span></a></li>
            </ul>
          

          <div id="files">
            <div class="file">
              <div class="meta">
                <div class="info">
                  <span class="icon"><img alt="Txt" height="16" src="https://assets1.github.com/images/icons/txt.png?fb793a9f8ae4a3436e27e4628ed81ae1e79a1661" width="16" /></span>
                  <span class="mode" title="File Mode">100755</span>
                  
                    <span>225 lines (210 sloc)</span>
                  
                  <span>7.116 kb</span>
                </div>
                <ul class="actions">
                  <li><a href="/TrinityCore/TrinityCore/raw/master/src/server/shared/Database/Implementation/CharacterDatabase.h" id="raw-url">raw</a></li>
                  
                    <li><a href="/TrinityCore/TrinityCore/blame/master/src/server/shared/Database/Implementation/CharacterDatabase.h">blame</a></li>
                  
                  <li><a href="/TrinityCore/TrinityCore/commits/master/src/server/shared/Database/Implementation/CharacterDatabase.h">history</a></li>
                </ul>
              </div>
              
  <div class="data type-c">
    
      <table cellpadding="0" cellspacing="0">
        <tr>
          <td>
            <pre class="line_numbers"><span id="LID1" rel="#L1">1</span>
<span id="LID2" rel="#L2">2</span>
<span id="LID3" rel="#L3">3</span>
<span id="LID4" rel="#L4">4</span>
<span id="LID5" rel="#L5">5</span>
<span id="LID6" rel="#L6">6</span>
<span id="LID7" rel="#L7">7</span>
<span id="LID8" rel="#L8">8</span>
<span id="LID9" rel="#L9">9</span>
<span id="LID10" rel="#L10">10</span>
<span id="LID11" rel="#L11">11</span>
<span id="LID12" rel="#L12">12</span>
<span id="LID13" rel="#L13">13</span>
<span id="LID14" rel="#L14">14</span>
<span id="LID15" rel="#L15">15</span>
<span id="LID16" rel="#L16">16</span>
<span id="LID17" rel="#L17">17</span>
<span id="LID18" rel="#L18">18</span>
<span id="LID19" rel="#L19">19</span>
<span id="LID20" rel="#L20">20</span>
<span id="LID21" rel="#L21">21</span>
<span id="LID22" rel="#L22">22</span>
<span id="LID23" rel="#L23">23</span>
<span id="LID24" rel="#L24">24</span>
<span id="LID25" rel="#L25">25</span>
<span id="LID26" rel="#L26">26</span>
<span id="LID27" rel="#L27">27</span>
<span id="LID28" rel="#L28">28</span>
<span id="LID29" rel="#L29">29</span>
<span id="LID30" rel="#L30">30</span>
<span id="LID31" rel="#L31">31</span>
<span id="LID32" rel="#L32">32</span>
<span id="LID33" rel="#L33">33</span>
<span id="LID34" rel="#L34">34</span>
<span id="LID35" rel="#L35">35</span>
<span id="LID36" rel="#L36">36</span>
<span id="LID37" rel="#L37">37</span>
<span id="LID38" rel="#L38">38</span>
<span id="LID39" rel="#L39">39</span>
<span id="LID40" rel="#L40">40</span>
<span id="LID41" rel="#L41">41</span>
<span id="LID42" rel="#L42">42</span>
<span id="LID43" rel="#L43">43</span>
<span id="LID44" rel="#L44">44</span>
<span id="LID45" rel="#L45">45</span>
<span id="LID46" rel="#L46">46</span>
<span id="LID47" rel="#L47">47</span>
<span id="LID48" rel="#L48">48</span>
<span id="LID49" rel="#L49">49</span>
<span id="LID50" rel="#L50">50</span>
<span id="LID51" rel="#L51">51</span>
<span id="LID52" rel="#L52">52</span>
<span id="LID53" rel="#L53">53</span>
<span id="LID54" rel="#L54">54</span>
<span id="LID55" rel="#L55">55</span>
<span id="LID56" rel="#L56">56</span>
<span id="LID57" rel="#L57">57</span>
<span id="LID58" rel="#L58">58</span>
<span id="LID59" rel="#L59">59</span>
<span id="LID60" rel="#L60">60</span>
<span id="LID61" rel="#L61">61</span>
<span id="LID62" rel="#L62">62</span>
<span id="LID63" rel="#L63">63</span>
<span id="LID64" rel="#L64">64</span>
<span id="LID65" rel="#L65">65</span>
<span id="LID66" rel="#L66">66</span>
<span id="LID67" rel="#L67">67</span>
<span id="LID68" rel="#L68">68</span>
<span id="LID69" rel="#L69">69</span>
<span id="LID70" rel="#L70">70</span>
<span id="LID71" rel="#L71">71</span>
<span id="LID72" rel="#L72">72</span>
<span id="LID73" rel="#L73">73</span>
<span id="LID74" rel="#L74">74</span>
<span id="LID75" rel="#L75">75</span>
<span id="LID76" rel="#L76">76</span>
<span id="LID77" rel="#L77">77</span>
<span id="LID78" rel="#L78">78</span>
<span id="LID79" rel="#L79">79</span>
<span id="LID80" rel="#L80">80</span>
<span id="LID81" rel="#L81">81</span>
<span id="LID82" rel="#L82">82</span>
<span id="LID83" rel="#L83">83</span>
<span id="LID84" rel="#L84">84</span>
<span id="LID85" rel="#L85">85</span>
<span id="LID86" rel="#L86">86</span>
<span id="LID87" rel="#L87">87</span>
<span id="LID88" rel="#L88">88</span>
<span id="LID89" rel="#L89">89</span>
<span id="LID90" rel="#L90">90</span>
<span id="LID91" rel="#L91">91</span>
<span id="LID92" rel="#L92">92</span>
<span id="LID93" rel="#L93">93</span>
<span id="LID94" rel="#L94">94</span>
<span id="LID95" rel="#L95">95</span>
<span id="LID96" rel="#L96">96</span>
<span id="LID97" rel="#L97">97</span>
<span id="LID98" rel="#L98">98</span>
<span id="LID99" rel="#L99">99</span>
<span id="LID100" rel="#L100">100</span>
<span id="LID101" rel="#L101">101</span>
<span id="LID102" rel="#L102">102</span>
<span id="LID103" rel="#L103">103</span>
<span id="LID104" rel="#L104">104</span>
<span id="LID105" rel="#L105">105</span>
<span id="LID106" rel="#L106">106</span>
<span id="LID107" rel="#L107">107</span>
<span id="LID108" rel="#L108">108</span>
<span id="LID109" rel="#L109">109</span>
<span id="LID110" rel="#L110">110</span>
<span id="LID111" rel="#L111">111</span>
<span id="LID112" rel="#L112">112</span>
<span id="LID113" rel="#L113">113</span>
<span id="LID114" rel="#L114">114</span>
<span id="LID115" rel="#L115">115</span>
<span id="LID116" rel="#L116">116</span>
<span id="LID117" rel="#L117">117</span>
<span id="LID118" rel="#L118">118</span>
<span id="LID119" rel="#L119">119</span>
<span id="LID120" rel="#L120">120</span>
<span id="LID121" rel="#L121">121</span>
<span id="LID122" rel="#L122">122</span>
<span id="LID123" rel="#L123">123</span>
<span id="LID124" rel="#L124">124</span>
<span id="LID125" rel="#L125">125</span>
<span id="LID126" rel="#L126">126</span>
<span id="LID127" rel="#L127">127</span>
<span id="LID128" rel="#L128">128</span>
<span id="LID129" rel="#L129">129</span>
<span id="LID130" rel="#L130">130</span>
<span id="LID131" rel="#L131">131</span>
<span id="LID132" rel="#L132">132</span>
<span id="LID133" rel="#L133">133</span>
<span id="LID134" rel="#L134">134</span>
<span id="LID135" rel="#L135">135</span>
<span id="LID136" rel="#L136">136</span>
<span id="LID137" rel="#L137">137</span>
<span id="LID138" rel="#L138">138</span>
<span id="LID139" rel="#L139">139</span>
<span id="LID140" rel="#L140">140</span>
<span id="LID141" rel="#L141">141</span>
<span id="LID142" rel="#L142">142</span>
<span id="LID143" rel="#L143">143</span>
<span id="LID144" rel="#L144">144</span>
<span id="LID145" rel="#L145">145</span>
<span id="LID146" rel="#L146">146</span>
<span id="LID147" rel="#L147">147</span>
<span id="LID148" rel="#L148">148</span>
<span id="LID149" rel="#L149">149</span>
<span id="LID150" rel="#L150">150</span>
<span id="LID151" rel="#L151">151</span>
<span id="LID152" rel="#L152">152</span>
<span id="LID153" rel="#L153">153</span>
<span id="LID154" rel="#L154">154</span>
<span id="LID155" rel="#L155">155</span>
<span id="LID156" rel="#L156">156</span>
<span id="LID157" rel="#L157">157</span>
<span id="LID158" rel="#L158">158</span>
<span id="LID159" rel="#L159">159</span>
<span id="LID160" rel="#L160">160</span>
<span id="LID161" rel="#L161">161</span>
<span id="LID162" rel="#L162">162</span>
<span id="LID163" rel="#L163">163</span>
<span id="LID164" rel="#L164">164</span>
<span id="LID165" rel="#L165">165</span>
<span id="LID166" rel="#L166">166</span>
<span id="LID167" rel="#L167">167</span>
<span id="LID168" rel="#L168">168</span>
<span id="LID169" rel="#L169">169</span>
<span id="LID170" rel="#L170">170</span>
<span id="LID171" rel="#L171">171</span>
<span id="LID172" rel="#L172">172</span>
<span id="LID173" rel="#L173">173</span>
<span id="LID174" rel="#L174">174</span>
<span id="LID175" rel="#L175">175</span>
<span id="LID176" rel="#L176">176</span>
<span id="LID177" rel="#L177">177</span>
<span id="LID178" rel="#L178">178</span>
<span id="LID179" rel="#L179">179</span>
<span id="LID180" rel="#L180">180</span>
<span id="LID181" rel="#L181">181</span>
<span id="LID182" rel="#L182">182</span>
<span id="LID183" rel="#L183">183</span>
<span id="LID184" rel="#L184">184</span>
<span id="LID185" rel="#L185">185</span>
<span id="LID186" rel="#L186">186</span>
<span id="LID187" rel="#L187">187</span>
<span id="LID188" rel="#L188">188</span>
<span id="LID189" rel="#L189">189</span>
<span id="LID190" rel="#L190">190</span>
<span id="LID191" rel="#L191">191</span>
<span id="LID192" rel="#L192">192</span>
<span id="LID193" rel="#L193">193</span>
<span id="LID194" rel="#L194">194</span>
<span id="LID195" rel="#L195">195</span>
<span id="LID196" rel="#L196">196</span>
<span id="LID197" rel="#L197">197</span>
<span id="LID198" rel="#L198">198</span>
<span id="LID199" rel="#L199">199</span>
<span id="LID200" rel="#L200">200</span>
<span id="LID201" rel="#L201">201</span>
<span id="LID202" rel="#L202">202</span>
<span id="LID203" rel="#L203">203</span>
<span id="LID204" rel="#L204">204</span>
<span id="LID205" rel="#L205">205</span>
<span id="LID206" rel="#L206">206</span>
<span id="LID207" rel="#L207">207</span>
<span id="LID208" rel="#L208">208</span>
<span id="LID209" rel="#L209">209</span>
<span id="LID210" rel="#L210">210</span>
<span id="LID211" rel="#L211">211</span>
<span id="LID212" rel="#L212">212</span>
<span id="LID213" rel="#L213">213</span>
<span id="LID214" rel="#L214">214</span>
<span id="LID215" rel="#L215">215</span>
<span id="LID216" rel="#L216">216</span>
<span id="LID217" rel="#L217">217</span>
<span id="LID218" rel="#L218">218</span>
<span id="LID219" rel="#L219">219</span>
<span id="LID220" rel="#L220">220</span>
<span id="LID221" rel="#L221">221</span>
<span id="LID222" rel="#L222">222</span>
<span id="LID223" rel="#L223">223</span>
<span id="LID224" rel="#L224">224</span>
<span id="LID225" rel="#L225">225</span>
</pre>
          </td>
          <td width="100%">
            
              
                <div class="highlight"><pre><div class='line' id='LC1'><span class="cm">/*</span></div><div class='line' id='LC2'><span class="cm"> * Copyright (C) 2008-2011 TrinityCore &lt;http://www.trinitycore.org/&gt;</span></div><div class='line' id='LC3'><span class="cm"> *</span></div><div class='line' id='LC4'><span class="cm"> * This program is free software; you can redistribute it and/or modify it</span></div><div class='line' id='LC5'><span class="cm"> * under the terms of the GNU General Public License as published by the</span></div><div class='line' id='LC6'><span class="cm"> * Free Software Foundation; either version 2 of the License, or (at your</span></div><div class='line' id='LC7'><span class="cm"> * option) any later version.</span></div><div class='line' id='LC8'><span class="cm"> *</span></div><div class='line' id='LC9'><span class="cm"> * This program is distributed in the hope that it will be useful, but WITHOUT</span></div><div class='line' id='LC10'><span class="cm"> * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or</span></div><div class='line' id='LC11'><span class="cm"> * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for</span></div><div class='line' id='LC12'><span class="cm"> * more details.</span></div><div class='line' id='LC13'><span class="cm"> *</span></div><div class='line' id='LC14'><span class="cm"> * You should have received a copy of the GNU General Public License along</span></div><div class='line' id='LC15'><span class="cm"> * with this program. If not, see &lt;http://www.gnu.org/licenses/&gt;.</span></div><div class='line' id='LC16'><span class="cm"> */</span></div><div class='line' id='LC17'><br/></div><div class='line' id='LC18'><span class="cp">#ifndef _CHARACTERDATABASE_H</span></div><div class='line' id='LC19'><span class="cp">#define _CHARACTERDATABASE_H</span></div><div class='line' id='LC20'><br/></div><div class='line' id='LC21'><span class="cp">#include &quot;DatabaseWorkerPool.h&quot;</span></div><div class='line' id='LC22'><span class="cp">#include &quot;MySQLConnection.h&quot;</span></div><div class='line' id='LC23'><br/></div><div class='line' id='LC24'><span class="n">class</span> <span class="n">CharacterDatabaseConnection</span> <span class="o">:</span> <span class="n">public</span> <span class="n">MySQLConnection</span></div><div class='line' id='LC25'><span class="p">{</span></div><div class='line' id='LC26'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="nl">public:</span></div><div class='line' id='LC27'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="c1">//- Constructors for sync and async connections</span></div><div class='line' id='LC28'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">CharacterDatabaseConnection</span><span class="p">(</span><span class="n">MySQLConnectionInfo</span><span class="o">&amp;</span> <span class="n">connInfo</span><span class="p">)</span> <span class="o">:</span> <span class="n">MySQLConnection</span><span class="p">(</span><span class="n">connInfo</span><span class="p">)</span> <span class="p">{}</span></div><div class='line' id='LC29'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">CharacterDatabaseConnection</span><span class="p">(</span><span class="n">ACE_Activation_Queue</span><span class="o">*</span> <span class="n">q</span><span class="p">,</span> <span class="n">MySQLConnectionInfo</span><span class="o">&amp;</span> <span class="n">connInfo</span><span class="p">)</span> <span class="o">:</span> <span class="n">MySQLConnection</span><span class="p">(</span><span class="n">q</span><span class="p">,</span> <span class="n">connInfo</span><span class="p">)</span> <span class="p">{}</span></div><div class='line' id='LC30'><br/></div><div class='line' id='LC31'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="c1">//- Loads database type specific prepared statements</span></div><div class='line' id='LC32'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">bool</span> <span class="n">Open</span><span class="p">();</span></div><div class='line' id='LC33'><span class="p">};</span></div><div class='line' id='LC34'><br/></div><div class='line' id='LC35'><span class="k">typedef</span> <span class="n">DatabaseWorkerPool</span><span class="o">&lt;</span><span class="n">CharacterDatabaseConnection</span><span class="o">&gt;</span> <span class="n">CharacterDatabaseWorkerPool</span><span class="p">;</span></div><div class='line' id='LC36'><br/></div><div class='line' id='LC37'><span class="k">enum</span> <span class="n">CharacterDatabaseStatements</span></div><div class='line' id='LC38'><span class="p">{</span></div><div class='line' id='LC39'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="cm">/*  Naming standard for defines:</span></div><div class='line' id='LC40'><span class="cm">        {DB}_{SET/DEL/ADD/REP}_{Summary of data changed}</span></div><div class='line' id='LC41'><span class="cm">        When updating more than one field, consider looking at the calling function</span></div><div class='line' id='LC42'><span class="cm">        name for a suiting suffix.</span></div><div class='line' id='LC43'><span class="cm">    */</span></div><div class='line' id='LC44'><br/></div><div class='line' id='LC45'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">CHAR_DEL_QUEST_POOL_SAVE</span><span class="p">,</span></div><div class='line' id='LC46'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">CHAR_ADD_QUEST_POOL_SAVE</span><span class="p">,</span></div><div class='line' id='LC47'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">CHAR_DEL_OLD_GUILD_EVENT_LOGS</span><span class="p">,</span></div><div class='line' id='LC48'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">CHAR_DEL_OLD_GUILD_BANK_EVENT_LOGS</span><span class="p">,</span></div><div class='line' id='LC49'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">CHAR_DEL_NONEXISTENT_GUILD_BANK_ITEM</span><span class="p">,</span></div><div class='line' id='LC50'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">CHAR_DEL_NONEXISTENT_CHARACTER_GROUP_MEMBERS</span><span class="p">,</span></div><div class='line' id='LC51'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">CHAR_DEL_LEADERLESS_GROUPS</span><span class="p">,</span></div><div class='line' id='LC52'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">CHAR_DEL_TINY_GROUPS</span><span class="p">,</span></div><div class='line' id='LC53'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">CHAR_DEL_NONEXISTENT_GROUP_MEMBERS</span><span class="p">,</span></div><div class='line' id='LC54'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">CHAR_DEL_NONEXISTENT_GROUP_INSTANCES</span><span class="p">,</span></div><div class='line' id='LC55'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">CHAR_DEL_EXPIRED_BANS</span><span class="p">,</span></div><div class='line' id='LC56'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">CHAR_GET_GUID_BY_NAME</span><span class="p">,</span></div><div class='line' id='LC57'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">CHAR_ADD_BAN</span><span class="p">,</span></div><div class='line' id='LC58'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">CHAR_SET_NOT_BANNED</span><span class="p">,</span></div><div class='line' id='LC59'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">CHAR_GET_BANINFO</span><span class="p">,</span></div><div class='line' id='LC60'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">CHAR_GET_GUID_BY_NAME_FILTER</span><span class="p">,</span></div><div class='line' id='LC61'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">CHAR_GET_BANINFO_LIST</span><span class="p">,</span></div><div class='line' id='LC62'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">CHAR_GET_BANNED_NAME</span><span class="p">,</span></div><div class='line' id='LC63'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">CHAR_LOAD_PLAYER</span><span class="p">,</span></div><div class='line' id='LC64'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">CHAR_LOAD_PLAYER_GROUP</span><span class="p">,</span></div><div class='line' id='LC65'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">CHAR_LOAD_PLAYER_BOUNDINSTANCES</span><span class="p">,</span></div><div class='line' id='LC66'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">CHAR_LOAD_PLAYER_AURAS</span><span class="p">,</span></div><div class='line' id='LC67'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">CHAR_LOAD_PLAYER_SPELLS</span><span class="p">,</span></div><div class='line' id='LC68'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">CHAR_LOAD_PLAYER_QUESTSTATUS</span><span class="p">,</span></div><div class='line' id='LC69'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">CHAR_LOAD_PLAYER_DAILYQUESTSTATUS</span><span class="p">,</span></div><div class='line' id='LC70'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">CHAR_LOAD_PLAYER_WEKLYQUESTSTATUS</span><span class="p">,</span></div><div class='line' id='LC71'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">CHAR_LOAD_PLAYER_REPUTATION</span><span class="p">,</span></div><div class='line' id='LC72'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">CHAR_LOAD_PLAYER_INVENTORY</span><span class="p">,</span></div><div class='line' id='LC73'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">CHAR_LOAD_PLAYER_ACTIONS</span><span class="p">,</span></div><div class='line' id='LC74'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">CHAR_LOAD_PLAYER_ACTIONS_SPEC</span><span class="p">,</span></div><div class='line' id='LC75'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">CHAR_LOAD_PLAYER_MAILCOUNT</span><span class="p">,</span></div><div class='line' id='LC76'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">CHAR_LOAD_PLAYER_MAILDATE</span><span class="p">,</span></div><div class='line' id='LC77'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">CHAR_LOAD_PLAYER_SOCIALLIST</span><span class="p">,</span></div><div class='line' id='LC78'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">CHAR_LOAD_PLAYER_HOMEBIND</span><span class="p">,</span></div><div class='line' id='LC79'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">CHAR_LOAD_PLAYER_SPELLCOOLDOWNS</span><span class="p">,</span></div><div class='line' id='LC80'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">CHAR_LOAD_PLAYER_DECLINEDNAMES</span><span class="p">,</span></div><div class='line' id='LC81'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">CHAR_LOAD_PLAYER_GUILD</span><span class="p">,</span></div><div class='line' id='LC82'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">CHAR_LOAD_PLAYER_ARENAINFO</span><span class="p">,</span></div><div class='line' id='LC83'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">CHAR_LOAD_PLAYER_ACHIEVEMENTS</span><span class="p">,</span></div><div class='line' id='LC84'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">CHAR_LOAD_PLAYER_CRITERIAPROGRESS</span><span class="p">,</span></div><div class='line' id='LC85'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">CHAR_LOAD_PLAYER_EQUIPMENTSETS</span><span class="p">,</span></div><div class='line' id='LC86'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">CHAR_LOAD_PLAYER_BGDATA</span><span class="p">,</span></div><div class='line' id='LC87'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">CHAR_LOAD_PLAYER_GLYPHS</span><span class="p">,</span></div><div class='line' id='LC88'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">CHAR_LOAD_PLAYER_TALENTS</span><span class="p">,</span></div><div class='line' id='LC89'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">CHAR_LOAD_PLAYER_ACCOUNTDATA</span><span class="p">,</span></div><div class='line' id='LC90'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">CHAR_LOAD_PLAYER_SKILLS</span><span class="p">,</span></div><div class='line' id='LC91'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">CHAR_LOAD_PLAYER_RANDOMBG</span><span class="p">,</span></div><div class='line' id='LC92'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">CHAR_LOAD_PLAYER_ARENASTATS</span><span class="p">,</span></div><div class='line' id='LC93'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">CHAR_LOAD_PLAYER_BANNED</span><span class="p">,</span></div><div class='line' id='LC94'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">CHAR_LOAD_PLAYER_QUESTSTATUSREW</span><span class="p">,</span></div><div class='line' id='LC95'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">CHAR_LOAD_ACCOUNT_INSTANCELOCKTIMES</span><span class="p">,</span></div><div class='line' id='LC96'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">CHAR_LOAD_ACCOUNT_DATA</span><span class="p">,</span></div><div class='line' id='LC97'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">CHAR_LOAD_PLAYER_MAILITEMS</span><span class="p">,</span></div><div class='line' id='LC98'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">CHAR_LOAD_AUCTION_ITEMS</span><span class="p">,</span></div><div class='line' id='LC99'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">CHAR_ADD_AUCTION</span><span class="p">,</span></div><div class='line' id='LC100'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">CHAR_DEL_AUCTION</span><span class="p">,</span></div><div class='line' id='LC101'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">CHAR_LOAD_AUCTIONS</span><span class="p">,</span></div><div class='line' id='LC102'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">CHAR_ADD_MAIL</span><span class="p">,</span></div><div class='line' id='LC103'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">CHAR_DEL_MAIL</span><span class="p">,</span></div><div class='line' id='LC104'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">CHAR_ADD_MAIL_ITEM</span><span class="p">,</span></div><div class='line' id='LC105'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">CHAR_DEL_EMPTY_EXPIRED_MAIL</span><span class="p">,</span></div><div class='line' id='LC106'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">CHAR_GET_EXPIRED_MAIL</span><span class="p">,</span></div><div class='line' id='LC107'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">CHAR_GET_MAIL_ITEM_LITE</span><span class="p">,</span></div><div class='line' id='LC108'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">CHAR_SET_MAIL_RETURNED</span><span class="p">,</span></div><div class='line' id='LC109'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">CHAR_SET_MAIL_ITEM_RECEIVER</span><span class="p">,</span></div><div class='line' id='LC110'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">CHAR_SET_ITEM_OWNER</span><span class="p">,</span></div><div class='line' id='LC111'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">CHAR_LOAD_GUILD_BANK_ITEMS</span><span class="p">,</span></div><div class='line' id='LC112'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">CHAR_LOAD_ITEM_REFUNDS</span><span class="p">,</span></div><div class='line' id='LC113'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">CHAR_LOAD_ITEM_BOP_TRADE</span><span class="p">,</span></div><div class='line' id='LC114'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">CHAR_DEL_ITEM_BOP_TRADE</span><span class="p">,</span></div><div class='line' id='LC115'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">CHAR_ADD_ITEM_BOP_TRADE</span><span class="p">,</span></div><div class='line' id='LC116'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">CHAR_REP_INVENTORY_ITEM</span><span class="p">,</span></div><div class='line' id='LC117'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">CHAR_DEL_INVENTORY_ITEM</span><span class="p">,</span></div><div class='line' id='LC118'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">CHAR_ADD_ITEM_INSTANCE</span><span class="p">,</span></div><div class='line' id='LC119'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">CHAR_UPDATE_ITEM_INSTANCE</span><span class="p">,</span></div><div class='line' id='LC120'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">CHAR_UPDATE_ITEM_INSTANCE_ON_LOAD</span><span class="p">,</span></div><div class='line' id='LC121'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">CHAR_DEL_ITEM_INSTANCE</span><span class="p">,</span></div><div class='line' id='LC122'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">CHAR_UPDATE_GIFT_OWNER</span><span class="p">,</span></div><div class='line' id='LC123'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">CHAR_DEL_GIFT</span><span class="p">,</span></div><div class='line' id='LC124'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">CHAR_GET_ACCOUNT_BY_NAME</span><span class="p">,</span></div><div class='line' id='LC125'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">CHAR_DEL_ACCOUNT_INSTANCE_LOCK_TIMES</span><span class="p">,</span></div><div class='line' id='LC126'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">CHAR_ADD_ACCOUNT_INSTANCE_LOCK_TIMES</span><span class="p">,</span></div><div class='line' id='LC127'><br/></div><div class='line' id='LC128'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">CHAR_ADD_GUILD</span><span class="p">,</span></div><div class='line' id='LC129'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">CHAR_DEL_GUILD</span><span class="p">,</span></div><div class='line' id='LC130'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">CHAR_ADD_GUILD_MEMBER</span><span class="p">,</span></div><div class='line' id='LC131'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">CHAR_DEL_GUILD_MEMBER</span><span class="p">,</span></div><div class='line' id='LC132'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">CHAR_DEL_GUILD_MEMBERS</span><span class="p">,</span></div><div class='line' id='LC133'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">CHAR_ADD_GUILD_RANK</span><span class="p">,</span></div><div class='line' id='LC134'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">CHAR_DEL_GUILD_RANKS</span><span class="p">,</span></div><div class='line' id='LC135'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">CHAR_DEL_GUILD_LOWEST_RANK</span><span class="p">,</span></div><div class='line' id='LC136'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">CHAR_ADD_GUILD_BANK_TAB</span><span class="p">,</span></div><div class='line' id='LC137'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">CHAR_DEL_GUILD_BANK_TAB</span><span class="p">,</span></div><div class='line' id='LC138'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">CHAR_DEL_GUILD_BANK_TABS</span><span class="p">,</span></div><div class='line' id='LC139'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">CHAR_ADD_GUILD_BANK_ITEM</span><span class="p">,</span></div><div class='line' id='LC140'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">CHAR_DEL_GUILD_BANK_ITEM</span><span class="p">,</span></div><div class='line' id='LC141'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">CHAR_DEL_GUILD_BANK_ITEMS</span><span class="p">,</span></div><div class='line' id='LC142'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">CHAR_ADD_GUILD_BANK_RIGHT_DEFAULT</span><span class="p">,</span></div><div class='line' id='LC143'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">CHAR_ADD_GUILD_BANK_RIGHT</span><span class="p">,</span></div><div class='line' id='LC144'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">CHAR_DEL_GUILD_BANK_RIGHT</span><span class="p">,</span></div><div class='line' id='LC145'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">CHAR_DEL_GUILD_BANK_RIGHTS</span><span class="p">,</span></div><div class='line' id='LC146'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">CHAR_DEL_GUILD_BANK_RIGHTS_FOR_RANK</span><span class="p">,</span></div><div class='line' id='LC147'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">CHAR_ADD_GUILD_BANK_EVENTLOG</span><span class="p">,</span></div><div class='line' id='LC148'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">CHAR_DEL_GUILD_BANK_EVENTLOG</span><span class="p">,</span></div><div class='line' id='LC149'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">CHAR_DEL_GUILD_BANK_EVENTLOGS</span><span class="p">,</span></div><div class='line' id='LC150'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">CHAR_ADD_GUILD_EVENTLOG</span><span class="p">,</span></div><div class='line' id='LC151'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">CHAR_DEL_GUILD_EVENTLOG</span><span class="p">,</span></div><div class='line' id='LC152'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">CHAR_DEL_GUILD_EVENTLOGS</span><span class="p">,</span></div><div class='line' id='LC153'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">CHAR_SET_GUILD_MEMBER_PNOTE</span><span class="p">,</span></div><div class='line' id='LC154'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">CHAR_SET_GUILD_MEMBER_OFFNOTE</span><span class="p">,</span></div><div class='line' id='LC155'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">CHAR_SET_GUILD_MEMBER_RANK</span><span class="p">,</span></div><div class='line' id='LC156'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">CHAR_SET_GUILD_MOTD</span><span class="p">,</span></div><div class='line' id='LC157'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">CHAR_SET_GUILD_INFO</span><span class="p">,</span></div><div class='line' id='LC158'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">CHAR_SET_GUILD_LEADER</span><span class="p">,</span></div><div class='line' id='LC159'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">CHAR_SET_GUILD_RANK_NAME</span><span class="p">,</span></div><div class='line' id='LC160'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">CHAR_SET_GUILD_RANK_RIGHTS</span><span class="p">,</span></div><div class='line' id='LC161'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">CHAR_SET_GUILD_EMBLEM_INFO</span><span class="p">,</span></div><div class='line' id='LC162'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">CHAR_SET_GUILD_BANK_TAB_INFO</span><span class="p">,</span></div><div class='line' id='LC163'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">CHAR_SET_GUILD_BANK_MONEY</span><span class="p">,</span></div><div class='line' id='LC164'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">CHAR_SET_GUILD_BANK_EVENTLOG_TAB</span><span class="p">,</span></div><div class='line' id='LC165'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">CHAR_SET_GUILD_MEMBER_BANK_REM_MONEY</span><span class="p">,</span></div><div class='line' id='LC166'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">CHAR_SET_GUILD_MEMBER_BANK_TIME_MONEY</span><span class="p">,</span></div><div class='line' id='LC167'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">CHAR_RESET_GUILD_RANK_BANK_RESET_TIME</span><span class="p">,</span></div><div class='line' id='LC168'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">CHAR_SET_GUILD_RANK_BANK_MONEY</span><span class="p">,</span></div><div class='line' id='LC169'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">CHAR_SET_GUILD_BANK_TAB_TEXT</span><span class="p">,</span></div><div class='line' id='LC170'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">CHAR_SET_GUILD_MEMBER_BANK_TIME_REM_SLOTS0</span><span class="p">,</span></div><div class='line' id='LC171'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">CHAR_SET_GUILD_MEMBER_BANK_TIME_REM_SLOTS1</span><span class="p">,</span></div><div class='line' id='LC172'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">CHAR_SET_GUILD_MEMBER_BANK_TIME_REM_SLOTS2</span><span class="p">,</span></div><div class='line' id='LC173'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">CHAR_SET_GUILD_MEMBER_BANK_TIME_REM_SLOTS3</span><span class="p">,</span></div><div class='line' id='LC174'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">CHAR_SET_GUILD_MEMBER_BANK_TIME_REM_SLOTS4</span><span class="p">,</span></div><div class='line' id='LC175'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">CHAR_SET_GUILD_MEMBER_BANK_TIME_REM_SLOTS5</span><span class="p">,</span></div><div class='line' id='LC176'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">CHAR_SET_GUILD_MEMBER_BANK_REM_SLOTS0</span><span class="p">,</span></div><div class='line' id='LC177'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">CHAR_SET_GUILD_MEMBER_BANK_REM_SLOTS1</span><span class="p">,</span></div><div class='line' id='LC178'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">CHAR_SET_GUILD_MEMBER_BANK_REM_SLOTS2</span><span class="p">,</span></div><div class='line' id='LC179'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">CHAR_SET_GUILD_MEMBER_BANK_REM_SLOTS3</span><span class="p">,</span></div><div class='line' id='LC180'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">CHAR_SET_GUILD_MEMBER_BANK_REM_SLOTS4</span><span class="p">,</span></div><div class='line' id='LC181'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">CHAR_SET_GUILD_MEMBER_BANK_REM_SLOTS5</span><span class="p">,</span></div><div class='line' id='LC182'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">CHAR_RESET_GUILD_RANK_BANK_TIME0</span><span class="p">,</span></div><div class='line' id='LC183'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">CHAR_RESET_GUILD_RANK_BANK_TIME1</span><span class="p">,</span></div><div class='line' id='LC184'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">CHAR_RESET_GUILD_RANK_BANK_TIME2</span><span class="p">,</span></div><div class='line' id='LC185'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">CHAR_RESET_GUILD_RANK_BANK_TIME3</span><span class="p">,</span></div><div class='line' id='LC186'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">CHAR_RESET_GUILD_RANK_BANK_TIME4</span><span class="p">,</span></div><div class='line' id='LC187'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">CHAR_RESET_GUILD_RANK_BANK_TIME5</span><span class="p">,</span></div><div class='line' id='LC188'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">CHAR_LOAD_GUILDS</span><span class="p">,</span></div><div class='line' id='LC189'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">CHAR_LOAD_GUILD_RANKS</span><span class="p">,</span></div><div class='line' id='LC190'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">CHAR_LOAD_CHAR_DATA_FOR_GUILD</span><span class="p">,</span></div><div class='line' id='LC191'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">CHAR_LOAD_GUILD_MEMBERS</span><span class="p">,</span></div><div class='line' id='LC192'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">CHAR_LOAD_GUILD_BANK_RIGHTS</span><span class="p">,</span></div><div class='line' id='LC193'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">CHAR_LOAD_GUILD_BANK_TABS</span><span class="p">,</span></div><div class='line' id='LC194'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">CHAR_LOAD_GUILD_EVENTLOGS</span><span class="p">,</span></div><div class='line' id='LC195'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">CHAR_LOAD_GUILD_BANK_EVENTLOGS</span><span class="p">,</span></div><div class='line' id='LC196'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">CHAR_CLEAN_GUILD_RANKS</span><span class="p">,</span></div><div class='line' id='LC197'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">CHAR_CLEAN_GUILD_MEMBERS</span><span class="p">,</span></div><div class='line' id='LC198'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">CHAR_CLEAN_GUILD_BANK_TABS</span><span class="p">,</span></div><div class='line' id='LC199'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">CHAR_CLEAN_GUILD_BANK_RIGHTS</span><span class="p">,</span></div><div class='line' id='LC200'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">CHAR_CLEAN_GUILD_BANK_ITEMS</span><span class="p">,</span></div><div class='line' id='LC201'><br/></div><div class='line' id='LC202'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">CHAR_DEL_CREATURE_RESPAWN_TIME</span><span class="p">,</span></div><div class='line' id='LC203'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">CHAR_ADD_CREATURE_RESPAWN_TIME</span><span class="p">,</span></div><div class='line' id='LC204'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">CHAR_DEL_EXPIRED_GO_RESPAWN_TIMES</span><span class="p">,</span></div><div class='line' id='LC205'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">CHAR_DEL_GO_RESPAWN_TIME</span><span class="p">,</span></div><div class='line' id='LC206'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">CHAR_ADD_GO_RESPAWN_TIME</span><span class="p">,</span></div><div class='line' id='LC207'><br/></div><div class='line' id='LC208'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">CHAR_LOAD_CHANNEL</span><span class="p">,</span></div><div class='line' id='LC209'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">CHAR_ADD_CHANNEL</span><span class="p">,</span></div><div class='line' id='LC210'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">CHAR_SET_CHANNEL</span><span class="p">,</span></div><div class='line' id='LC211'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">CHAR_SET_CHANNEL_USAGE</span><span class="p">,</span></div><div class='line' id='LC212'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">CHAR_CLEAN_CHANNEL</span><span class="p">,</span></div><div class='line' id='LC213'><br/></div><div class='line' id='LC214'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">CHAR_SET_EQUIP_SET</span><span class="p">,</span></div><div class='line' id='LC215'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">CHAR_ADD_EQUIP_SET</span><span class="p">,</span></div><div class='line' id='LC216'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">CHAR_DEL_EQUIP_SET</span><span class="p">,</span></div><div class='line' id='LC217'><br/></div><div class='line' id='LC218'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">CHAR_DEL_AURA</span><span class="p">,</span></div><div class='line' id='LC219'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">CHAR_ADD_AURA</span><span class="p">,</span></div><div class='line' id='LC220'><br/></div><div class='line' id='LC221'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">MAX_CHARACTERDATABASE_STATEMENTS</span><span class="p">,</span></div><div class='line' id='LC222'><span class="p">};</span></div><div class='line' id='LC223'><br/></div><div class='line' id='LC224'><span class="cp">#endif</span></div><div class='line' id='LC225'><br/></div></pre></div>
              
            
          </td>
        </tr>
      </table>
    
  </div>


            </div>
          </div>
        </div>
      </div>
    

    </div>
  



<div class="frame frame-loading" style="display:none;">
  <img src="/images/modules/ajax/big_spinner_336699.gif">
</div>
    </div>
  
      
    </div>

    <div id="footer" class="clearfix">
      <div class="site">
        <div class="sponsor">
          <a href="http://www.rackspace.com" class="logo">
            <img alt="Dedicated Server" src="https://assets1.github.com/images/modules/footer/rackspace_logo.png?v2?fb793a9f8ae4a3436e27e4628ed81ae1e79a1661" />
          </a>
          Powered by the <a href="http://www.rackspace.com ">Dedicated
          Servers</a> and<br/> <a href="http://www.rackspacecloud.com">Cloud
          Computing</a> of Rackspace Hosting<span>&reg;</span>
        </div>

        <ul class="links">
          <li class="blog"><a href="https://github.com/blog">Blog</a></li>
          <li><a href="http://support.github.com?sso=mGPSibZqwaHwunkkvCuPO_P3U0OqBzwAZeCzAZpFzQJnPvHqYea1kjWIpiFOkV4H8uVADaDAT4PbjRG46CAZ56kyn8Re63a18vZvkxs-ReeESthPesHkHaaWVFXWDzPhKSSy5epZMuFKG7CnS57VuFynkMfiib1jvbCXRel6F9lnNyx7lgWj93KhRY02UVcTdXC4rQha6ai12NdQf7jmcx4CUUKQ2XCFndjmWIq_fwg">Support</a></li>
          <li><a href="https://github.com/training">Training</a></li>
          <li><a href="http://jobs.github.com">Job Board</a></li>
          <li><a href="http://shop.github.com">Shop</a></li>
          <li><a href="https://github.com/contact">Contact</a></li>
          <li><a href="http://develop.github.com">API</a></li>
          <li><a href="http://status.github.com">Status</a></li>
        </ul>
        <ul class="sosueme">
          <li class="main">&copy; 2011 <span id="_rrt" title="0.09073s from fe3.rs.github.com">GitHub</span> Inc. All rights reserved.</li>
          <li><a href="/site/terms">Terms of Service</a></li>
          <li><a href="/site/privacy">Privacy</a></li>
          <li><a href="https://github.com/security">Security</a></li>
        </ul>
      </div>
    </div><!-- /#footer -->

    
      
      
        <!-- current locale: en -->
        <div class="locales">
          <div class="site">

            <ul class="choices clearfix limited-locales">
              <li><span class="current">English</span></li>
              
                  <li><a rel="nofollow" href="?locale=de">Deutsch</a></li>
              
                  <li><a rel="nofollow" href="?locale=fr">Français</a></li>
              
                  <li><a rel="nofollow" href="?locale=ja">日本語</a></li>
              
                  <li><a rel="nofollow" href="?locale=pt-BR">Português (BR)</a></li>
              
                  <li><a rel="nofollow" href="?locale=ru">Русский</a></li>
              
                  <li><a rel="nofollow" href="?locale=zh">中文</a></li>
              
              <li class="all"><a href="#" class="minibutton btn-forward js-all-locales"><span><span class="icon"></span>See all available languages</span></a></li>
            </ul>

            <div class="all-locales clearfix">
              <h3>Your current locale selection: <strong>English</strong>. Choose another?</h3>
              
              
                <ul class="choices">
                  
                      <li><a rel="nofollow" href="?locale=en">English</a></li>
                  
                      <li><a rel="nofollow" href="?locale=af">Afrikaans</a></li>
                  
                      <li><a rel="nofollow" href="?locale=ca">Català</a></li>
                  
                      <li><a rel="nofollow" href="?locale=cs">Čeština</a></li>
                  
                </ul>
              
                <ul class="choices">
                  
                      <li><a rel="nofollow" href="?locale=de">Deutsch</a></li>
                  
                      <li><a rel="nofollow" href="?locale=es">Español</a></li>
                  
                      <li><a rel="nofollow" href="?locale=fr">Français</a></li>
                  
                      <li><a rel="nofollow" href="?locale=hr">Hrvatski</a></li>
                  
                </ul>
              
                <ul class="choices">
                  
                      <li><a rel="nofollow" href="?locale=id">Indonesia</a></li>
                  
                      <li><a rel="nofollow" href="?locale=it">Italiano</a></li>
                  
                      <li><a rel="nofollow" href="?locale=ja">日本語</a></li>
                  
                      <li><a rel="nofollow" href="?locale=nl">Nederlands</a></li>
                  
                </ul>
              
                <ul class="choices">
                  
                      <li><a rel="nofollow" href="?locale=no">Norsk</a></li>
                  
                      <li><a rel="nofollow" href="?locale=pl">Polski</a></li>
                  
                      <li><a rel="nofollow" href="?locale=pt-BR">Português (BR)</a></li>
                  
                      <li><a rel="nofollow" href="?locale=ru">Русский</a></li>
                  
                </ul>
              
                <ul class="choices">
                  
                      <li><a rel="nofollow" href="?locale=sr">Српски</a></li>
                  
                      <li><a rel="nofollow" href="?locale=sv">Svenska</a></li>
                  
                      <li><a rel="nofollow" href="?locale=zh">中文</a></li>
                  
                </ul>
              
            </div>

          </div>
          <div class="fade"></div>
        </div>
      
    

    <script>window._auth_token = "c086c05c70524d684506124042635de51e28db34"</script>
    <div id="keyboard_shortcuts_pane" style="display:none">
  <h2>Keyboard Shortcuts</h2>

  <div class="columns threecols">
    <div class="column first">
      <h3>Site wide shortcuts</h3>
      <dl class="keyboard-mappings">
        <dt>s</dt>
        <dd>Focus site search</dd>
      </dl>
      <dl class="keyboard-mappings">
        <dt>?</dt>
        <dd>Bring up this help dialog</dd>
      </dl>
    </div><!-- /.column.first -->
    <div class="column middle">
      <h3>Commit list</h3>
      <dl class="keyboard-mappings">
        <dt>j</dt>
        <dd>Move selected down</dd>
      </dl>
      <dl class="keyboard-mappings">
        <dt>k</dt>
        <dd>Move selected up</dd>
      </dl>
      <dl class="keyboard-mappings">
        <dt>t</dt>
        <dd>Open tree</dd>
      </dl>
      <dl class="keyboard-mappings">
        <dt>p</dt>
        <dd>Open parent</dd>
      </dl>
      <dl class="keyboard-mappings">
        <dt>c <em>or</em> o <em>or</em> enter</dt>
        <dd>Open commit</dd>
      </dl>
    </div><!-- /.column.first -->
    <div class="column last">
      <h3>Pull request list</h3>
      <dl class="keyboard-mappings">
        <dt>j</dt>
        <dd>Move selected down</dd>
      </dl>
      <dl class="keyboard-mappings">
        <dt>k</dt>
        <dd>Move selected up</dd>
      </dl>
      <dl class="keyboard-mappings">
        <dt>o <em>or</em> enter</dt>
        <dd>Open issue</dd>
      </dl>
    </div><!-- /.columns.last -->
  </div><!-- /.columns.equacols -->

  <div class="rule"></div>

  <h3>Issues</h3>

  <div class="columns threecols">
    <div class="column first">
      <dl class="keyboard-mappings">
        <dt>j</dt>
        <dd>Move selected down</dd>
      </dl>
      <dl class="keyboard-mappings">
        <dt>k</dt>
        <dd>Move selected up</dd>
      </dl>
      <dl class="keyboard-mappings">
        <dt>x</dt>
        <dd>Toggle select target</dd>
      </dl>
      <dl class="keyboard-mappings">
        <dt>o <em>or</em> enter</dt>
        <dd>Open issue</dd>
      </dl>
    </div><!-- /.column.first -->
    <div class="column middle">
      <dl class="keyboard-mappings">
        <dt>I</dt>
        <dd>Mark selected as read</dd>
      </dl>
      <dl class="keyboard-mappings">
        <dt>U</dt>
        <dd>Mark selected as unread</dd>
      </dl>
      <dl class="keyboard-mappings">
        <dt>e</dt>
        <dd>Close selected</dd>
      </dl>
      <dl class="keyboard-mappings">
        <dt>y</dt>
        <dd>Remove selected from view</dd>
      </dl>
    </div><!-- /.column.middle -->
    <div class="column last">
      <dl class="keyboard-mappings">
        <dt>c</dt>
        <dd>Create issue</dd>
      </dl>
      <dl class="keyboard-mappings">
        <dt>l</dt>
        <dd>Create label</dd>
      </dl>
      <dl class="keyboard-mappings">
        <dt>i</dt>
        <dd>Back to inbox</dd>
      </dl>
      <dl class="keyboard-mappings">
        <dt>u</dt>
        <dd>Back to issues</dd>
      </dl>
      <dl class="keyboard-mappings">
        <dt>/</dt>
        <dd>Focus issues search</dd>
      </dl>
    </div>
  </div>

  <div class="rule"></div>

  <h3>Network Graph</h3>
  <div class="columns equacols">
    <div class="column first">
      <dl class="keyboard-mappings">
        <dt>← <em>or</em> h</dt>
        <dd>Scroll left</dd>
      </dl>
      <dl class="keyboard-mappings">
        <dt>→ <em>or</em> l</dt>
        <dd>Scroll right</dd>
      </dl>
      <dl class="keyboard-mappings">
        <dt>↑ <em>or</em> k</dt>
        <dd>Scroll up</dd>
      </dl>
      <dl class="keyboard-mappings">
        <dt>↓ <em>or</em> j</dt>
        <dd>Scroll down</dd>
      </dl>
      <dl class="keyboard-mappings">
        <dt>t</dt>
        <dd>Toggle visibility of head labels</dd>
      </dl>
    </div><!-- /.column.first -->
    <div class="column last">
      <dl class="keyboard-mappings">
        <dt>shift ← <em>or</em> shift h</dt>
        <dd>Scroll all the way left</dd>
      </dl>
      <dl class="keyboard-mappings">
        <dt>shift → <em>or</em> shift l</dt>
        <dd>Scroll all the way right</dd>
      </dl>
      <dl class="keyboard-mappings">
        <dt>shift ↑ <em>or</em> shift k</dt>
        <dd>Scroll all the way up</dd>
      </dl>
      <dl class="keyboard-mappings">
        <dt>shift ↓ <em>or</em> shift j</dt>
        <dd>Scroll all the way down</dd>
      </dl>
    </div><!-- /.column.last -->
  </div>

</div>
    

    <!--[if IE 8]>
    <script type="text/javascript" charset="utf-8">
      $(document.body).addClass("ie8")
    </script>
    <![endif]-->

    <!--[if IE 7]>
    <script type="text/javascript" charset="utf-8">
      $(document.body).addClass("ie7")
    </script>
    <![endif]-->

    <script type="text/javascript">
      _kmq.push(['trackClick', 'entice-signup-button', 'Entice banner clicked']);
      
    </script>
    
  </body>
</html>

