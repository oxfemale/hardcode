// ============================================================================
//  genasminc.c - generate include file for asm functions
// ---------------------------------------------------------------------------
//  MiniFMOD public source code release.
//  This source is provided as-is.  Firelight Multimedia will not support
//  or answer questions about the source provided.
//  MiniFMOD Sourcecode is copyright (c) 2000, Firelight Multimedia.
//  MiniFMOD Sourcecode is in no way representative of FMOD 3 source.
//  Firelight Multimedia is a registered business name.
//  This source must not be redistributed without this notice.
// ----------------------------------------------------------------------------
//  This source file is copyright (c) 2002, Luks <luks@host.sk>
// ===========================================================================

#include <stdio.h>
#include "minifmod.h"
#include "sound.h"
#include "music.h"
#include "mixer.h"

#define offset(a,b) ((int)(&a.b)-(int)(&a))

int main()
{
  FSOUND_CHANNEL t1;
  FSOUND_SAMPLE  t2;
  FMUSIC_CHANNEL t3;
  
  printf("; this file is generated by genasminc\n");
  
  printf("%%define FSOUND_NORMAL %i\n", FSOUND_NORMAL);
  printf("%%define FSOUND_LOOP_OFF %i\n", FSOUND_LOOP_OFF);
  printf("%%define FSOUND_LOOP_NORMAL %i\n", FSOUND_LOOP_NORMAL);
  printf("%%define FSOUND_LOOP_BIDI %i\n", FSOUND_LOOP_BIDI);
  printf("%%define FSOUND_8BITS %i\n", FSOUND_8BITS);
  printf("%%define FSOUND_16BITS %i\n", FSOUND_16BITS);
  printf("%%define FSOUND_MONO %i\n", FSOUND_MONO);
  printf("%%define FSOUND_STEREO %i\n", FSOUND_STEREO);
  printf("%%define FSOUND_UNSIGNED %i\n", FSOUND_UNSIGNED);
  printf("%%define FSOUND_SIGNED %i\n", FSOUND_SIGNED);
  printf("%%define FSOUND_DELTA %i\n", FSOUND_DELTA);
  printf("%%define FSOUND_IT214 %i\n", FSOUND_IT214);
  printf("%%define FSOUND_IT215 %i\n", FSOUND_IT215);
  
  printf("%%define FSOUND_MIXDIR_FORWARDS %i\n", FSOUND_MIXDIR_FORWARDS);
  printf("%%define FSOUND_MIXDIR_BACKWARDS %i\n", FSOUND_MIXDIR_BACKWARDS);
  
  printf("%%define FSOUND_OUTPUTBUFF_END %i\n", FSOUND_OUTPUTBUFF_END);
  printf("%%define FSOUND_SAMPLEBUFF_END %i\n", FSOUND_SAMPLEBUFF_END);
  printf("%%define FSOUND_VOLUMERAMP_END %i\n", FSOUND_VOLUMERAMP_END);

  printf("%%define FSOUND_CHANNEL.index %i\n", offset(t1,index));
  printf("%%define FSOUND_CHANNEL.volume %i\n", offset(t1,volume));
  printf("%%define FSOUND_CHANNEL.frequency %i\n", offset(t1,frequency));
  printf("%%define FSOUND_CHANNEL.pan %i\n", offset(t1,pan));
  printf("%%define FSOUND_CHANNEL.actualvolume %i\n", offset(t1,actualvolume));
  printf("%%define FSOUND_CHANNEL.actualpan %i\n", offset(t1,actualpan));
  printf("%%define FSOUND_CHANNEL.sampleoffset %i\n", offset(t1,sampleoffset));
  printf("%%define FSOUND_CHANNEL.sptr %i\n", offset(t1,sptr));
  printf("%%define FSOUND_CHANNEL.leftvolume %i\n", offset(t1,leftvolume));
  printf("%%define FSOUND_CHANNEL.rightvolume %i\n", offset(t1,rightvolume));
  printf("%%define FSOUND_CHANNEL.mixpos %i\n", offset(t1,mixpos));
  printf("%%define FSOUND_CHANNEL.mixposlo %i\n", offset(t1,mixposlo));
  printf("%%define FSOUND_CHANNEL.speedlo %i\n", offset(t1,speedlo));
  printf("%%define FSOUND_CHANNEL.speedhi %i\n", offset(t1,speedhi));
  printf("%%define FSOUND_CHANNEL.speeddir %i\n", offset(t1,speeddir));
  printf("%%define FSOUND_CHANNEL.ramp_lefttarget %i\n", offset(t1,ramp_lefttarget));
  printf("%%define FSOUND_CHANNEL.ramp_righttarget %i\n", offset(t1,ramp_righttarget));
  printf("%%define FSOUND_CHANNEL.ramp_leftvolume %i\n", offset(t1,ramp_leftvolume));
  printf("%%define FSOUND_CHANNEL.ramp_rightvolume %i\n", offset(t1,ramp_rightvolume));
  printf("%%define FSOUND_CHANNEL.ramp_leftspeed %i\n", offset(t1,ramp_leftspeed));
  printf("%%define FSOUND_CHANNEL.ramp_rightspeed %i\n", offset(t1,ramp_rightspeed));
  printf("%%define FSOUND_CHANNEL.ramp_count %i\n", offset(t1,ramp_count));
  
  printf("%%define FSOUND_SAMPLE.buff %i\n", offset(t2,buff));
  printf("%%define FSOUND_SAMPLE.length %i\n", offset(t2,length));
  printf("%%define FSOUND_SAMPLE.loopstart %i\n", offset(t2,loopstart));
  printf("%%define FSOUND_SAMPLE.looplen %i\n", offset(t2,looplen));
  printf("%%define FSOUND_SAMPLE.defvol %i\n", offset(t2,defvol));
  printf("%%define FSOUND_SAMPLE.finetune %i\n", offset(t2,finetune));
  printf("%%define FSOUND_SAMPLE.deffreq %i\n", offset(t2,deffreq));
  printf("%%define FSOUND_SAMPLE.defpan %i\n", offset(t2,defpan));
  printf("%%define FSOUND_SAMPLE.bits %i\n", offset(t2,bits));
  printf("%%define FSOUND_SAMPLE.loopmode %i\n", offset(t2,loopmode));
  printf("%%define FSOUND_SAMPLE.globalvol %i\n", offset(t2,globalvol));
  printf("%%define FSOUND_SAMPLE.relative %i\n", offset(t2,relative));
  printf("%%define FSOUND_SAMPLE.middlec %i\n", offset(t2,middlec));
  printf("%%define FSOUND_SAMPLE.susloopbegin %i\n", offset(t2,susloopbegin));
  printf("%%define FSOUND_SAMPLE.susloopend %i\n", offset(t2,susloopend));
  printf("%%define FSOUND_SAMPLE.vibspeed %i\n", offset(t2,vibspeed));
  printf("%%define FSOUND_SAMPLE.vibdepth %i\n", offset(t2,vibdepth));
  printf("%%define FSOUND_SAMPLE.vibtype %i\n", offset(t2,vibtype));
  printf("%%define FSOUND_SAMPLE.vibrate %i\n", offset(t2,vibrate));

  printf("%%define FMUSIC_CHANNEL.note %i\n", offset(t3,note));
  printf("%%define FMUSIC_CHANNEL.samp %i\n", offset(t3,samp));
  printf("%%define FMUSIC_CHANNEL.notectrl %i\n", offset(t3,notectrl));
  printf("%%define FMUSIC_CHANNEL.cptr %i\n", offset(t3,cptr));
  printf("%%define FMUSIC_CHANNEL.sptr %i\n", offset(t3,sptr));
  printf("%%define FMUSIC_CHANNEL.freq %i\n", offset(t3,freq));
  printf("%%define FMUSIC_CHANNEL.volume %i\n", offset(t3,volume));
  printf("%%define FMUSIC_CHANNEL.pan %i\n", offset(t3,pan));
  printf("%%define FMUSIC_CHANNEL.voldelta %i\n", offset(t3,voldelta));
  printf("%%define FMUSIC_CHANNEL.freqdelta %i\n", offset(t3,freqdelta));
  printf("%%define FMUSIC_CHANNEL.pandelta %i\n", offset(t3,pandelta));
  printf("%%define FMUSIC_CHANNEL.samp_globalvol %i\n", offset(t3,samp_globalvol));
  printf("%%define FMUSIC_CHANNEL.envvoltick %i\n", offset(t3,envvoltick));
  printf("%%define FMUSIC_CHANNEL.envvolpos %i\n", offset(t3,envvolpos));
  printf("%%define FMUSIC_CHANNEL.envvolfrac %i\n", offset(t3,envvolfrac));
  printf("%%define FMUSIC_CHANNEL.envvol %i\n", offset(t3,envvol));
  printf("%%define FMUSIC_CHANNEL.envvoldelta %i\n", offset(t3,envvoldelta));
  printf("%%define FMUSIC_CHANNEL.envvolstopped %i\n", offset(t3,envvolstopped));
  printf("%%define FMUSIC_CHANNEL.envpantick %i\n", offset(t3,envpantick));
  printf("%%define FMUSIC_CHANNEL.envpanpos %i\n", offset(t3,envpanpos));
  printf("%%define FMUSIC_CHANNEL.envpanfrac %i\n", offset(t3,envpanfrac));
  printf("%%define FMUSIC_CHANNEL.envpan %i\n", offset(t3,envpan));
  printf("%%define FMUSIC_CHANNEL.envpandelta %i\n", offset(t3,envpandelta));
  printf("%%define FMUSIC_CHANNEL.envpanstopped %i\n", offset(t3,envpanstopped));
  printf("%%define FMUSIC_CHANNEL.fadeoutvol %i\n", offset(t3,fadeoutvol));
  printf("%%define FMUSIC_CHANNEL.ivibpos %i\n", offset(t3,ivibpos));
  printf("%%define FMUSIC_CHANNEL.ivibsweeppos %i\n", offset(t3,ivibsweeppos));
  printf("%%define FMUSIC_CHANNEL.fade %i\n", offset(t3,fade));
  printf("%%define FMUSIC_CHANNEL.keyoff %i\n", offset(t3,keyoff));
  printf("%%define FMUSIC_CHANNEL.inst %i\n", offset(t3,inst));
  printf("%%define FMUSIC_CHANNEL.realnote %i\n", offset(t3,realnote));
  printf("%%define FMUSIC_CHANNEL.period %i\n", offset(t3,period));
  printf("%%define FMUSIC_CHANNEL.recenteffect %i\n", offset(t3,recenteffect));
  printf("%%define FMUSIC_CHANNEL.sampleoffset %i\n", offset(t3,sampleoffset));
  printf("%%define FMUSIC_CHANNEL.globalvolume %i\n", offset(t3,globalvolume));
  printf("%%define FMUSIC_CHANNEL.portadown %i\n", offset(t3,portadown));
  printf("%%define FMUSIC_CHANNEL.portaup %i\n", offset(t3,portaup));
  printf("%%define FMUSIC_CHANNEL.xtraportadown %i\n", offset(t3,xtraportadown));
  printf("%%define FMUSIC_CHANNEL.xtraportaup %i\n", offset(t3,xtraportaup));
  printf("%%define FMUSIC_CHANNEL.volslide %i\n", offset(t3,volslide));
  printf("%%define FMUSIC_CHANNEL.panslide %i\n", offset(t3,panslide));
  printf("%%define FMUSIC_CHANNEL.retrigx %i\n", offset(t3,retrigx));
  printf("%%define FMUSIC_CHANNEL.retrigy %i\n", offset(t3,retrigy));
  printf("%%define FMUSIC_CHANNEL.portatarget %i\n", offset(t3,portatarget));
  printf("%%define FMUSIC_CHANNEL.portaspeed %i\n", offset(t3,portaspeed));
  printf("%%define FMUSIC_CHANNEL.vibpos %i\n", offset(t3,vibpos));
  printf("%%define FMUSIC_CHANNEL.vibspeed %i\n", offset(t3,vibspeed));
  printf("%%define FMUSIC_CHANNEL.vibdepth %i\n", offset(t3,vibdepth));
  printf("%%define FMUSIC_CHANNEL.vibtype %i\n", offset(t3,vibtype));
  printf("%%define FMUSIC_CHANNEL.tremolopos %i\n", offset(t3,tremolopos));
  printf("%%define FMUSIC_CHANNEL.tremolospeed %i\n", offset(t3,tremolospeed));
  printf("%%define FMUSIC_CHANNEL.tremolodepth %i\n", offset(t3,tremolodepth));
  printf("%%define FMUSIC_CHANNEL.panbrellopos %i\n", offset(t3,panbrellopos));
  printf("%%define FMUSIC_CHANNEL.panbrellospeed %i\n", offset(t3,panbrellospeed));
  printf("%%define FMUSIC_CHANNEL.panbrellodepth %i\n", offset(t3,panbrellodepth));
  printf("%%define FMUSIC_CHANNEL.tremorpos %i\n", offset(t3,tremorpos));
  printf("%%define FMUSIC_CHANNEL.tremoron %i\n", offset(t3,tremoron));
  printf("%%define FMUSIC_CHANNEL.tremoroff %i\n", offset(t3,tremoroff));
  printf("%%define FMUSIC_CHANNEL.arpeggio %i\n", offset(t3,arpeggio));
  printf("%%define FMUSIC_CHANNEL.patlooprow %i\n", offset(t3,patlooprow));
  printf("%%define FMUSIC_CHANNEL.patloopno %i\n", offset(t3,patloopno));
  printf("%%define FMUSIC_CHANNEL.channelvsl %i\n", offset(t3,channelvsl));
  printf("%%define FMUSIC_CHANNEL.specialparam %i\n", offset(t3,specialparam));
  printf("%%define FMUSIC_CHANNEL.wavecontrol %i\n", offset(t3,wavecontrol));
  printf("%%define FMUSIC_CHANNEL.wavecontrolvib %i\n", offset(t3,wavecontrolvib));
  printf("%%define FMUSIC_CHANNEL.wavecontroltrem %i\n", offset(t3,wavecontroltrem));
  printf("%%define FMUSIC_CHANNEL.wavecontrolpan %i\n", offset(t3,wavecontrolpan));
  printf("%%define FMUSIC_CHANNEL.finevsldown %i\n", offset(t3,finevsldown));
  printf("%%define FMUSIC_CHANNEL.finevslup %i\n", offset(t3,finevslup));
  printf("%%define FMUSIC_CHANNEL.fineportaup %i\n", offset(t3,fineportaup));
  printf("%%define FMUSIC_CHANNEL.fineportadown %i\n", offset(t3,fineportadown));
  printf("%%define FMUSIC_CHANNEL.highoffset %i\n", offset(t3,highoffset));
  printf("%%define FMUSIC_CHANNEL.volcolumn_volslide %i\n", offset(t3,volcolumn_volslide));
										
  return(0);
}
