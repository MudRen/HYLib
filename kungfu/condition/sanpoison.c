//Cracked by Roath
#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

string* xuedao = ({
        "�ؿ�����",
        "ͷ���ٻ�",
        "����ӭ��",
        "���ӿȪ",
        "�����͹�",
        "����̫��",
});


int update_condition(object me, int duration)
{
	int neili, poison;

	if( !living(me) && userp(me) ) {
   	me->start_busy(random(1)+1);
//     		message_vision(me->name() + "����һ�������ʹ��غ���һ����\n", environment(me), me);
   	}
   	else {
   		if (me->query("family/family_name")=="������"
                    && me->query_skill("huagong-dafa")) {
                    tell_object(me, HIW"��ͻȻ����һ����Ϯ����æ���û����󷨵�����\n"NOR);
		    message("vision", me->name() + "������ͻȻ�������Σ����Ϸ���һ��Ұ�֮ɫ��\n",environment(me), me);	                    		   	
   		    
   		    poison=me->query_skill("poison",1)/2;		
   
   	
   		} else {	 		
      		    poison=10;
      		    tell_object(me, HIW"��ͻȻ�����"+xuedao[random(sizeof(xuedao))]+"һ���ʹ����ǰһ��ڣ�һ����������һ�����ơ�\n" NOR );
      		    message("vision", me->name() + "������ͻȻ�������Σ����Ϸ���һ��Ұ�֮ɫ��\n",environment(me), me);	                    		   	
   	        }
   	}
   	
   	neili=me->query("neili")-(me->query_skill("force",1));
   	me->start_busy(random(1)+1);
   	
   	if(neili<me->query_skill("force",1)*4) {
   	     
   	     tell_object(me, HIR"��������Ѿ��������Ʋ�ס���ڵĶ��أ�һ���ʹϮ��������ʵ�ѵ���\n" NOR );
   	     
   	     me->set("neili",0);		
if ((int)me->query("qi") < 100000)
{
   	     me->receive_damage("jing", (me->query("jing")/10));
      	     me->receive_wound("qi", (me->query("qi")/10));
}   	else    me->receive_wound("qi", 2000);	
   	} else me->set("neili",neili);  	
   	
      	me->apply_condition("sanpoison", duration - random(5));
	
//	if(me->query("qi")<=0){
//		me->set_temp("last_damage_from", "����ɢ����������");
//	        me->delete("env/immortal");
//		me->die();
//	}
	
	        
//   	if( duration == 1) me->delete("poisoner");

   	if( duration < 1 ) {
   		message_vision(HIG"$N�����������������ڵĺ����Ѿ���Ȼ�޴档"NOR,me);	
   		return 0;
   	}
   	
   return CND_CONTINUE;
}
