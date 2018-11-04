// vote unchblk
#include <vote.h> 
#include <ansi.h>
#include <net/dns.h>

inherit F_CONDITION;

int clear_vote(object victim);

int vote(object me, object victim)
{
  int reason; // vote for what?
  int vv;	// valid voter numbers
  int vc; 	// vote count;
  int df;

  string *juror, my_id;
  string my_name, v_name;

  if ((reason = (int)victim->query("vote/reason"))>0 && (reason!=V_UNCHBLK))
  {
  	return notify_fail("Ҫ�ѵ�ǰ�ı������Ժ�ſ������µĶ��顣\n");
  }
  
  if (time()-(int)victim->query("chblk_channel/all")>3600)
  	return notify_fail(victim->name()+"�Ľ�̸Ƶ���Ѿ��ǿ��ŵ��ˡ�\n");
  
  if (reason <= 0)
  {
  	victim->set("vote/reason", (int)V_UNCHBLK); 
  }
  
  my_id = me->query("id");

  // dont allow me to vote twice for the same issue
  juror = victim->query("vote/juror");
  
  if( !pointerp(juror) )
  {
 	victim->set("vote/juror", ({ my_id }) );
  } else if( member_array(my_id, juror) == -1 ) 
  {
 	victim->set("vote/juror", juror+({ my_id }) );
  } else
  {
	me->add("vote/abuse", 10);
  	return notify_fail("һ��һƱ�����ñ��Ȩ��Ҫ�ܳͷ��ģ�\n");
  }

  vv = (int) ("/cmds/std/vote")->valid_voters(me)/3;  
  vc = victim->add("vote/count", 1);
if (vv>6) vv=5;
  df = vv - vc;
  if (vv < 4) df = 4 - vc;
  
  my_name = me->name();
  if (me == victim) v_name = "�Լ�";
  	else  v_name = victim->name();

  if (df>1)
  {
	shout( HIG "�������"+my_name+"ͶƱ��" +v_name +"�Ľ�̸Ƶ��������"
			+sprintf("%d", df)+"Ʊ��\n" NOR);
	write( HIG "�������"+my_name+"ͶƱ��" +v_name +"�Ľ�̸Ƶ��������"
			+sprintf("%d", df)+"Ʊ��\n" NOR);
    
	victim->apply_condition("vote_clear", 10);
			        
  } else 
  {
  	if (me != victim)
  	{
	shout( HIG "�������"+my_name+"ͶƱ��" +v_name+"�Ľ�̸Ƶ����"
		+v_name+"�Ľ�̸Ƶ�������ˣ�\n" NOR);
	write( HIG "�������"+my_name+"ͶƱ��" +v_name+"�Ľ�̸Ƶ����"
		+v_name+"�Ľ�̸Ƶ�������ˣ�\n" NOR);
	} else 
	{
	shout( HIG "�������"+my_name+"ͶƱ���Լ��Ľ�̸Ƶ����"
		+my_name+"�Ľ�̸Ƶ�������ˣ�\n" NOR);
	write( HIG "�������"+my_name+"ͶƱ���Լ��Ľ�̸Ƶ����"
		+my_name+"�Ľ�̸Ƶ�������ˣ�\n" NOR);
	}		
	
	victim->apply_condition("vote_clear", -10);
	victim->delete("chblk_channel");
  } 
  
  return 1;
}

