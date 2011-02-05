<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN"
    "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="en" lang="en">
<head>
<title>vproc_priv.h</title>
<style type="text/css">
.enscript-comment { font-style: italic; color: rgb(178,34,34); }
.enscript-function-name { font-weight: bold; color: rgb(0,0,255); }
.enscript-variable-name { font-weight: bold; color: rgb(184,134,11); }
.enscript-keyword { font-weight: bold; color: rgb(160,32,240); }
.enscript-reference { font-weight: bold; color: rgb(95,158,160); }
.enscript-string { font-weight: bold; color: rgb(188,143,143); }
.enscript-builtin { font-weight: bold; color: rgb(218,112,214); }
.enscript-type { font-weight: bold; color: rgb(34,139,34); }
.enscript-highlight { text-decoration: underline; color: 0; }
</style>
</head>
<body id="top">
<h1 style="margin:8px;" id="f1">vproc_priv.h&nbsp;&nbsp;&nbsp;<span style="font-weight: normal; font-size: 0.5em;">[<a href="?txt">plain text</a>]</span></h1>
<hr/>
<div></div>
<pre>
#<span class="enscript-reference">ifndef</span> <span class="enscript-variable-name">_VPROC_PRIVATE_H_</span>
#<span class="enscript-reference">define</span> <span class="enscript-variable-name">_VPROC_PRIVATE_H_</span>
<span class="enscript-comment">/*
 * Copyright (c) 2006 Apple Computer, Inc. All rights reserved.
 *
 * @APPLE_APACHE_LICENSE_HEADER_START@
 * 
 * Licensed under the Apache License, Version 2.0 (the &quot;License&quot;);
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 *     <a href="http://www.apache.org/licenses/LICENSE-2.0">http://www.apache.org/licenses/LICENSE-2.0</a>
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an &quot;AS IS&quot; BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 * 
 * @APPLE_APACHE_LICENSE_HEADER_END@
 */</span>

#<span class="enscript-reference">include</span> <span class="enscript-string">&lt;Availability.h&gt;</span>
#<span class="enscript-reference">include</span> <span class="enscript-string">&lt;sys/types.h&gt;</span>
#<span class="enscript-reference">include</span> <span class="enscript-string">&lt;sys/cdefs.h&gt;</span>
#<span class="enscript-reference">include</span> <span class="enscript-string">&lt;sys/syslog.h&gt;</span>
#<span class="enscript-reference">include</span> <span class="enscript-string">&lt;sys/time.h&gt;</span>
#<span class="enscript-reference">include</span> <span class="enscript-string">&lt;stdbool.h&gt;</span>
#<span class="enscript-reference">include</span> <span class="enscript-string">&lt;launch.h&gt;</span>
#<span class="enscript-reference">include</span> <span class="enscript-string">&lt;vproc.h&gt;</span>
#<span class="enscript-reference">include</span> <span class="enscript-string">&lt;uuid/uuid.h&gt;</span>

#<span class="enscript-reference">ifndef</span> <span class="enscript-variable-name">VPROC_HAS_TRANSACTIONS</span>
	#define VPROC_HAS_TRANSACTIONS
#<span class="enscript-reference">endif</span>

__BEGIN_DECLS

#<span class="enscript-reference">pragma</span> <span class="enscript-variable-name">GCC</span> <span class="enscript-variable-name">visibility</span> <span class="enscript-variable-name">push</span>(<span class="enscript-variable-name">default</span>)

<span class="enscript-comment">/* DO NOT use this. This is a hack for 'launchctl' */</span>
#<span class="enscript-reference">define</span> <span class="enscript-variable-name">VPROC_MAGIC_UNLOAD_SIGNAL</span>	0x4141504C
<span class="enscript-comment">/* DO NOT use this. This is a hack for 'loginwindow' */</span>
#<span class="enscript-reference">define</span> <span class="enscript-variable-name">VPROC_MAGIC_TRYKILL_SIGNAL</span>	0x6161706C

<span class="enscript-type">typedef</span> <span class="enscript-type">enum</span> {
	VPROC_GSK_LAST_EXIT_STATUS = 1,
	VPROC_GSK_GLOBAL_ON_DEMAND,
	VPROC_GSK_MGR_UID,
	VPROC_GSK_MGR_PID,
	VPROC_GSK_IS_MANAGED,
	VPROC_GSK_MGR_NAME,
	VPROC_GSK_BASIC_KEEPALIVE,
	VPROC_GSK_START_INTERVAL,
	VPROC_GSK_IDLE_TIMEOUT,
	VPROC_GSK_EXIT_TIMEOUT,
	VPROC_GSK_ENVIRONMENT,
	VPROC_GSK_ALLJOBS,
	VPROC_GSK_GLOBAL_LOG_MASK,
	VPROC_GSK_GLOBAL_UMASK,
	VPROC_GSK_ABANDON_PROCESS_GROUP,
	VPROC_GSK_TRANSACTIONS_ENABLED,
	VPROC_GSK_WEIRD_BOOTSTRAP,
	VPROC_GSK_WAITFORDEBUGGER,
	VPROC_GSK_SECURITYSESSION,
	VPROC_GSK_SHUTDOWN_DEBUGGING,
	VPROC_GSK_VERBOSE_BOOT,
	VPROC_GSK_PERUSER_SUSPEND,
	VPROC_GSK_PERUSER_RESUME,
	VPROC_GSK_JOB_OVERRIDES_DB,
	VPROC_GSK_JOB_CACHE_DB,
	VPROC_GSK_EMBEDDEDROOTEQUIVALENT,
} vproc_gsk_t;

<span class="enscript-type">typedef</span> <span class="enscript-type">unsigned</span> <span class="enscript-type">int</span> vproc_flags_t;
<span class="enscript-comment">/* For _vproc_kickstart_by_label() -- instructs launchd to kickstart the job to stall before exec(2). */</span>
#<span class="enscript-reference">define</span> <span class="enscript-variable-name">VPROCFLAG_STALL_JOB_EXEC</span>	1 &lt;&lt; 1

vproc_t <span class="enscript-function-name">vprocmgr_lookup_vproc</span>(<span class="enscript-type">const</span> <span class="enscript-type">char</span> *label);
vproc_t <span class="enscript-function-name">vproc_retain</span>(vproc_t vp);
<span class="enscript-type">void</span> <span class="enscript-function-name">vproc_release</span>(vproc_t vp);

vproc_err_t <span class="enscript-function-name">vproc_swap_integer</span>(vproc_t vp, vproc_gsk_t key, int64_t *inval, int64_t *outval);
vproc_err_t <span class="enscript-function-name">vproc_swap_complex</span>(vproc_t vp, vproc_gsk_t key, launch_data_t inval, launch_data_t *outval);
vproc_err_t <span class="enscript-function-name">vproc_swap_string</span>(vproc_t vp, vproc_gsk_t key, <span class="enscript-type">const</span> <span class="enscript-type">char</span> *instr, <span class="enscript-type">char</span> **outstr);

vproc_err_t <span class="enscript-function-name">_vproc_get_last_exit_status</span>(<span class="enscript-type">int</span> *wstatus);
vproc_err_t <span class="enscript-function-name">_vproc_set_global_on_demand</span>(bool val);

<span class="enscript-type">typedef</span> <span class="enscript-function-name">void</span> (*_vprocmgr_log_drain_callback_t)(<span class="enscript-type">struct</span> timeval *when, pid_t from_pid, pid_t about_pid, uid_t sender_uid, gid_t sender_gid, <span class="enscript-type">int</span> priority, <span class="enscript-type">const</span> <span class="enscript-type">char</span> *from_name, <span class="enscript-type">const</span> <span class="enscript-type">char</span> *about_name, <span class="enscript-type">const</span> <span class="enscript-type">char</span> *session_name, <span class="enscript-type">const</span> <span class="enscript-type">char</span> *msg);

vproc_err_t <span class="enscript-function-name">_vprocmgr_log_drain</span>(vproc_t vp, pthread_mutex_t *optional_mutex_around_callback, _vprocmgr_log_drain_callback_t func);

vproc_err_t <span class="enscript-function-name">_vproc_send_signal_by_label</span>(<span class="enscript-type">const</span> <span class="enscript-type">char</span> *label, <span class="enscript-type">int</span> sig);
vproc_err_t <span class="enscript-function-name">_vproc_kickstart_by_label</span>(<span class="enscript-type">const</span> <span class="enscript-type">char</span> *label, pid_t *out_pid, mach_port_t *out_port_name, mach_port_t *out_obsrvr_port, vproc_flags_t flags);
vproc_err_t <span class="enscript-function-name">_vproc_wait_by_label</span>(<span class="enscript-type">const</span> <span class="enscript-type">char</span> *label, <span class="enscript-type">int</span> *out_wstatus);

<span class="enscript-type">void</span> <span class="enscript-function-name">_vproc_log</span>(<span class="enscript-type">int</span> pri, <span class="enscript-type">const</span> <span class="enscript-type">char</span> *msg, ...) __attribute__((format(printf, 2, 3)));
<span class="enscript-type">void</span> <span class="enscript-function-name">_vproc_log_error</span>(<span class="enscript-type">int</span> pri, <span class="enscript-type">const</span> <span class="enscript-type">char</span> *msg, ...) __attribute__((format(printf, 2, 3)));
<span class="enscript-type">void</span> <span class="enscript-function-name">_vproc_logv</span>(<span class="enscript-type">int</span> pri, <span class="enscript-type">int</span> err, <span class="enscript-type">const</span> <span class="enscript-type">char</span> *msg, va_list ap) __attribute__((format(printf, 3, 0)));

#<span class="enscript-reference">define</span> <span class="enscript-variable-name">VPROCMGR_SESSION_LOGINWINDOW</span>	<span class="enscript-string">&quot;LoginWindow&quot;</span>
#<span class="enscript-reference">define</span> <span class="enscript-variable-name">VPROCMGR_SESSION_BACKGROUND</span>		<span class="enscript-string">&quot;Background&quot;</span>
#<span class="enscript-reference">define</span> <span class="enscript-variable-name">VPROCMGR_SESSION_AQUA</span>			<span class="enscript-string">&quot;Aqua&quot;</span>
#<span class="enscript-reference">define</span> <span class="enscript-variable-name">VPROCMGR_SESSION_STANDARDIO</span>		<span class="enscript-string">&quot;StandardIO&quot;</span>
#<span class="enscript-reference">define</span> <span class="enscript-variable-name">VPROCMGR_SESSION_SYSTEM</span>			<span class="enscript-string">&quot;System&quot;</span>

vproc_err_t <span class="enscript-function-name">_vprocmgr_move_subset_to_user</span>(uid_t target_user, <span class="enscript-type">const</span> <span class="enscript-type">char</span> *session_type, uint64_t flags);
vproc_err_t <span class="enscript-function-name">_vprocmgr_switch_to_session</span>(<span class="enscript-type">const</span> <span class="enscript-type">char</span> *target_session, vproc_flags_t flags);
vproc_err_t <span class="enscript-function-name">_vprocmgr_detach_from_console</span>(vproc_flags_t flags);

<span class="enscript-type">void</span> <span class="enscript-function-name">_vproc_standby_begin</span>(<span class="enscript-type">void</span>)																__OSX_AVAILABLE_STARTING(__MAC_10_6, __IPHONE_NA);
<span class="enscript-type">void</span> <span class="enscript-function-name">_vproc_standby_end</span>(<span class="enscript-type">void</span>)																__OSX_AVAILABLE_STARTING(__MAC_10_6, __IPHONE_NA);
size_t <span class="enscript-function-name">_vproc_standby_count</span>(<span class="enscript-type">void</span>)															__OSX_AVAILABLE_STARTING(__MAC_10_6, __IPHONE_NA);
size_t <span class="enscript-function-name">_vproc_standby_timeout</span>(<span class="enscript-type">void</span>)															__OSX_AVAILABLE_STARTING(__MAC_10_6, __IPHONE_NA);

kern_return_t <span class="enscript-function-name">_vproc_transaction_count_for_pid</span>(pid_t p, int32_t *count, bool *condemned)	__OSX_AVAILABLE_STARTING(__MAC_10_6, __IPHONE_NA);
bool <span class="enscript-function-name">_vproc_pid_is_managed</span>(pid_t p)															__OSX_AVAILABLE_STARTING(__MAC_10_6, __IPHONE_NA);
<span class="enscript-type">void</span> <span class="enscript-function-name">_vproc_transaction_try_exit</span>(<span class="enscript-type">int</span> status)												__OSX_AVAILABLE_STARTING(__MAC_10_6, __IPHONE_NA);
<span class="enscript-type">void</span> <span class="enscript-function-name">_vproc_transaction_begin</span>(<span class="enscript-type">void</span>)															__OSX_AVAILABLE_STARTING(__MAC_10_6, __IPHONE_NA);
<span class="enscript-type">void</span> <span class="enscript-function-name">_vproc_transaction_end</span>(<span class="enscript-type">void</span>)															__OSX_AVAILABLE_STARTING(__MAC_10_6, __IPHONE_NA);
size_t <span class="enscript-function-name">_vproc_transaction_count</span>(<span class="enscript-type">void</span>)														__OSX_AVAILABLE_STARTING(__MAC_10_6, __IPHONE_NA);

#<span class="enscript-reference">pragma</span> <span class="enscript-variable-name">GCC</span> <span class="enscript-variable-name">visibility</span> <span class="enscript-variable-name">pop</span>

__END_DECLS

#<span class="enscript-reference">endif</span>
</pre>
<hr />
</body></html>