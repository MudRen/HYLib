#ifndef SHIPDIR
#define SHIPDIR __DIR__"NODEFINE"
#endif

#ifndef FROM
#define FROM __DIR__"NODEFINE"
#endif

#ifndef TO
#define TO __DIR__"NODEFINE"
#endif

#include <ansi.h>


void init()
{
	object here;
	
	add_action("do_yell","yell");
	
	here = load_object(FROM);
	if(strsrch(here->query("short"),"��")!=-1)
		add_action("do_du","dujiang");
	else
		add_action("do_du","duhe");
}

int do_yell(string arg)
{
	object ship,here,me;
	int force;
	
	ship=find_object(SHIPDIR);
	ship=load_object(SHIPDIR);
	me=this_player();
	here=environment(me);
	force=me->query("neili");
	
	if(!arg||arg!="boat") return notify_fail("��Ҫ����ʲô?\n");
	if(force<=500) message_vision("\n$Nʹ�������������������ҡ�����!��\n",me);
	else if(force<=1000) message_vision("\n$N���������������ҡ�����!������ԶԶ���˳�ȥ��\n",me);
	else if(force<=2000) message_vision("\n$N�����������������������ҡ�����!������ԶԶ���˳�ȥ��\n",me);
	else message_vision("\n$N���������������ҡ�����!����������,���ò�Ϣ��\n",me);
	if(!ship)
		return notify_fail("�㷢�ִ������ˣ��챨����ʦ�ɣ�\n");
	if(ship->query("yell"))
		if(ship->query("exits/out")==FROM)
			return notify_fail("��������,�����ϾͿ���!\n");
	else return notify_fail("\n�������������ȵȰ�������һ������ˡ���������\n\n");
	ship->set("yell",1);
	ship->set("exits/out",FROM);
	here->set("exits/enter",SHIPDIR);
	tell_object(here,"\n����˵�������͹�,�����õ���,�����ϴ���!��\n");
	tell_object(here,"�����������壬�����˰��ߣ�enter����\n\n");
	call_out("on_board",10,me,ship,here);
	return 1;
}

void on_board(object me,object ship,object here)
{
   tell_object(ship,"��������������λ�͹�����,�����ˡ���������\n");
   tell_object(here,"��������������λ�͹�����,�����ˡ���������\n");
   ship->delete("exits");
   here->delete("exits/enter");
   call_out("leave_ship",30,me,ship);
   remove_call_out("on_board");
}

void leave_ship(object me,object ship)
{
	object here;
	
	ship->set("exits/out",TO);
    here=load_object(TO);
	tell_object(ship,"����˵�������͹�,������,�´���!��\n");
	
	call_out("no_ship",1,ship,here);
	remove_call_out("leave_ship");
}

void no_ship(object ship,object here)
{
   object *ob;int i;
   ob=all_inventory(ship);
   for(i=0;i<sizeof(ob);i++)
   {
	   if(living(ob[i])){
	   	   message_vision("\n$N���������Ļ��������˴���\n",ob[i]);
	   	   tell_object(here,ob[i]->name()+"�Ӵ�������������\n");
		   ob[i]->move(here);
	   }
	   else
	   {
		   tell_object(ship,"����һ�Ű�"+ob[i]->name()+"���´�!\n");
		   tell_object(here,"����һ�Ű�"+ob[i]->name()+"���´�!\n");
		   ob[i]->move(here);
	   }
   }
   ship->delete("exits");
   ship->delete("yell");
   //here->delete("exits/enter");
   remove_call_out("no_ship");
}

int do_du()
{
	object ob;object where;
  	ob=this_player();
  
  	if(environment(ob)->query("no_duhe"))
  		return 0;
  
  	if(ob->is_busy())
  		return notify_fail("����æ���أ��Ȼ�ɣ�\n");
 	if(ob->query_temp("track"))
 		return notify_fail("���������γ��������޷��ɽ���\n");
  	if(ob->query("max_neili")<2000)
  		return notify_fail("�������������ʹ�������Ṧ��\n");
  	if(ob->query("neili")<200)
  		return notify_fail("�������������ʹ�������Ṧ��\n");
  	if(environment(ob)->query("exits/enter"))
  		return notify_fail("�д���������ʲôCOOL����\n");
  	if(ob->query("neili")<210)
  		message_vision(HIW"$N"+HIW+"��������һ�Σ���԰���ȥ��\n"NOR,ob);
  	else 
  	if(ob->query("neili")<250)
  		message_vision(HIG"$N"+HIW+"��������������ˮ����԰���Ʈ��ȥ��\n"NOR,ob);
  	else 
  		message_vision(HIC"$N"+HIC+"����΢΢һ�Σ����̰�س��԰�Ʈ�˹�ȥ��\n"NOR,ob);
  	ob->add("neili",-200);
  	where=load_object(SHIPDIR);
  	ob->move(where);
  	message_vision(HIG"$N"+HIG+"������һ̤��ͷ����������ǰ��ȥ��\n"NOR,ob);
  	where=load_object(TO);
  	ob->move(TO);
  	message_vision(HIG"$N"+HIG+"ƮȻ��أ�����������һ��������\n"NOR,ob);
  	ob->start_busy(1);
  	return 1;
}