//yaochu.c ҩ��
//����II���������䣩
//����lywin 2000/6/15

#include <ansi.h>
inherit ITEM;

string *she1=({"/d/shenlong/npc/dushe","/d/shenlong/npc/jinshe","/d/shenlong/npc/qingshe"});
string *she2=({"/d/shenlong/npc/fushe"});
string *yao1=({"/quest/liandan/yaocao1","quest/liandan/yaocao2"});

void init()
{
	add_action("do_wayao", "wayao");
}

void create()
{
	set_name("ҩ��", ({"yao chu", "chu"}));
        set_temp("workchu", 8);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("no_drop","��Ҫ�Ҷ����ⶫ������ʹ��\n");
		set("no_put",1);
		set("long", "����һ����ҩ�����������������ҩ��wayao����\n");
		set("value", 0);
	}
	setup();
}

int do_wayao()
{
string file;
string *roomlines;
string location;
string room;
object ob;
object ob1;
object me=this_player();
int filei;
	//quests = read_table("/quest/dynamic_quest");
//file = read_file("/clone/medicine/yc1");
//roomlines = explode(file,"\n");	
//location = roomlines[random(sizeof(roomlines))];
//write location;
room=environment(me)->query("long");
filei=strsrch(room,"ɽ��");
if (filei<=0) filei=strsrch(room,"��ɽ");
if (filei<=0) filei=strsrch(room,"ɭ��");
if (filei<=0) filei=strsrch(room,"Ϫˮ");
if (filei<=0) filei=strsrch(room,"��ԭ");

	if (filei >0 && random(2)==0)
{
       environment(me)->set_temp("wayaono",1);
}
  	
	if( file = environment(me)->query("no_fight"))
		return notify_fail("�����ҩ�����ѱ����ڹ��ˡ�\n");

if( environment(me)->query("outdoors")=="migong")
return notify_fail("�����ҩ�����ѱ����ڹ��ˡ�\n");

if( file = environment(me)->query_temp("wayaono"))
return notify_fail("�����ҩ�����ѱ����ڹ��ˡ�\n");

//tell_object(me,location);
//if (filei <=0) tell_object(me,"��ҩ");
//if (filei >0) tell_object(me,"��ҩ");
//tell_object(me,filei);
//        ob1 = new(location);
//        ob1->move(me);


        if (me->is_busy())
        {
          tell_object(me,"����æ���ˣ����ڰɣ���\n");
          return 1;
        }
	if( me->is_fighting() )
        {
          tell_object(me,"�ȴ����ˣ����ڰɣ���\n");
          return 1;
        }

if (environment(me))
{
        if (present("dushe", environment(me))
        || present("qing she", environment(me))
        || present("jin she", environment(me))
        || present("fu she", environment(me)))
        {  
          tell_object(me,"�ȰѶ��߸ɵ��ɣ�\n");
          return 1;
        }
}
        if ((me->query("jing") < 20))
        {  
          tell_object(me,"��ľ������ܼ��У���������ҩ��\n");
          return 1;
        }
        else
        if ((me->query("qi") < 30 ))
        {
          tell_object(me,"�������״̬̫�������ҩ��\n");
          return 1;
        }
        else
        if ((int)me->query_condition("skill2_busy"))  
            {
         tell_object(me,"��ողŸɹ���,Ҫ��Ϣһ���ˣ�\n");
                      return 1;
            }
        else          
	if (environment(me)->query_temp("wayao1") >= 1)
        {
        message_vision(HIC"$N�Ӷ�ҩ����ʼ�ڵ�������������\n"NOR,me);
        me->add("jing",-10);
        me->add("qi",-20);
        me->start_busy(8);   
       	call_out("wayao1",3,me);
       	me->stop_busy();
       	return 1;
      	}
      	else
	if (environment(me)->query_temp("wayao2") >= 1)
        {
        message_vision(HIC"$N�Ӷ�ҩ����ʼ�ڵ�������������\n"NOR,me);
        me->add("jing",-20);
        me->add("qi",-30);
        me->start_busy(8);   
       	call_out("wayao2",4,me);
       	me->stop_busy();
       	return 1;
      	}
      	else
	if (filei >0 )
        {
if( !file = environment(me)->query("outdoors"))
return notify_fail("ֻ�л�����п�����ҩ�ţ��뵽�������Ұɡ�\n");

        message_vision(HIC"$N�Ӷ�ҩ����ʼ�ڵ�������������\n"NOR,me);
        me->add("jing",-20);
        me->add("qi",-30);
        me->start_busy(8);   
       	call_out("wayao3",4,me);
       	me->stop_busy();
       	return 1;
      	}      	
        return notify_fail("�����ҩ�����ѱ����ڹ��ˡ�\n");
}

int wayao1(object me)
{
      object ob;
      object ob1;        

      if(random(7)<2) 
      {         
        tell_room(environment(me),HIY"�ݴ���һ��ζ���ͻȻ���һ���ߡ�\n"NOR );
        ob=new(she1[random(3)]);
        ob->move(environment(me));
        ob->kill(me);
        ob->set_leader(me);
        me->start_busy(2);
      }
      else
      if (random(7)<3)
      {
          message_vision(CYN"һ�������󣬲ݴ����ƺ�û��$NҪ�ҵĶ�����$Nʧ����̾�˿�����\n"NOR,me);

      }
      else
      { 
        message_vision(HIG"$N���˰��죬���ڷ�������һ������������Ĳ����в�ͬ��С������ؾ��˳�����\n"NOR,me); 
//        message_vision(HIG"ҩ�ݵ����ڵ��ˣ���ϧҩ��ȴ��С�����ˡ�\n"NOR,me); 
        ob1 = new( __DIR__ "yaocao1");
        ob1->move(me);
        add_temp("workchu", -1);
        environment(me)->add_temp("wayao1",-1);
        environment(me)->set_temp("wayaob",1);
        me->apply_condition("skill2_busy",1+random(1));
                me->start_busy(1);
        if ( query_temp("workchu") < 1)
             {
    message_vision(HIG"ҩ�ݵ����ڵ��ˣ���ϧҩ��ȴ��С�����ˡ�\n"NOR,me); 
        destruct(this_object());
             }
      }
      return 1;
}

int wayao2(object me)
{
      object ob;
      object ob1;        

      if(random(7)<2) 
      {         
        tell_room(environment(me),HIY"�ݴ���һ��ζ���ͻȻ���һ���ߡ�\n"NOR );
        ob=new(she2[random(1)]);
        ob->kill(me);
        ob->set_leader(me);
        ob->move(environment(me));
        me->start_busy(2);
      }
      else
      if (random(7)<3)
      {
          message_vision(CYN"һ�������󣬲ݴ����ƺ�û��$NҪ�ҵĶ�����$Nʧ����̾�˿�����\n"NOR,me);

      }
      else
      { 
        message_vision(HIG"$N���˰��죬���ڷ�������һ������������Ĳ����в�ͬ��С������ؾ��˳�����\n"NOR,me); 
        ob1 = new(yao1[random(2)]);
        ob1->move(me);
        environment(me)->add_temp("wayao2",-1);
        environment(me)->set_temp("wayaog",1);
        me->apply_condition("skill2_busy",1+random(1));
        add_temp("workchu", -1);
        me->start_busy(1);
        if ( query_temp("workchu") < 1)
             {
    message_vision(HIG"ҩ�ݵ����ڵ��ˣ���ϧҩ��ȴ��С�����ˡ�\n"NOR,me); 
        destruct(this_object());
             }
      }
      return 1;
}


int wayao3(object me)
{
      object ob;
      object ob1;        
string file;
string *roomlines;
string location;
string room;
me=this_player();
file = read_file("/clone/medicine/yc1");
roomlines = explode(file,"\n");	
location = roomlines[random(sizeof(roomlines))];

      if(random(7)<2 && !wizardp(me)) 
      {         
        tell_room(environment(me),HIY"�ݴ���һ��ζ���ͻȻ���һ���ߡ�\n"NOR );
        ob=new(she2[random(1)]);
        ob->kill(me);
        ob->set_leader(me);
        ob->move(environment(me));
        me->start_busy(2);
      }
      else
      if (random(7)<3 && !wizardp(me))
      {
          message_vision(CYN"һ�������󣬲ݴ����ƺ�û��$NҪ�ҵĶ�����$Nʧ����̾�˿�����\n"NOR,me);

      }
      else
      { 
        message_vision(HIG"$N���˰��죬���ڷ���������Χ��һ������������ҩ ��С����������˳�����\n"NOR,me); 
        
        ob1 = new(location);
        ob1->move(me);
        message_vision(HIG"$N�ҵ���"+ob1->query("name")+"��\n"NOR,me); 
        environment(me)->set_temp("wayaono",1);
        me->apply_condition("skill2_busy",2+random(1));
        add_temp("workchu", -1);
        me->start_busy(1);
        if ( query_temp("workchu") < 1)
             {
    message_vision(HIG"ҩ�ݵ����ڵ��ˣ���ϧҩ��ȴ��С�����ˡ�\n"NOR,me); 
        destruct(this_object());
             }
      }
      return 1;
}