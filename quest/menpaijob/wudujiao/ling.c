// liangong-fu.c

inherit ITEM;
#include <ansi.h>
//int do_shouzhang();
int consider_lv(object ob,int a);
static int i = random(9)+3;
void create()
{
        set_name("�嶾������", ({ "wd lingqi"}));
        set("long", "һ���嶾������,�������ĵ���һ�㸺��ӭ������yingji");
        set_weight(300);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("material", "paper");
                set("value", 0);
                set("unit", "��");
        }
        setup();
}

void init()
{
        add_action("do_shouzhang","yingji");
}
int do_shouzhang()
{
object ob,me=this_player();
string targ;
object obj;
int maxpot;
if (!environment(me))  return notify_fail("���ﲻ��Ҫ��ӭ���ĵط�!\n");
if (environment(me)->query("short") !=me->query_temp("wdhwjob"))
return notify_fail("���ǽ��㵽"+me->query_temp("wdhwjob")+"ȥӭ����!\n");
if(!me->query_temp("wdhw"))
return notify_fail("�㲻����������������\n");
if (this_object()->query("usename")!=me->query("name"))
return notify_fail("�ⲻ���������!!\n");

        if (me->is_busy())
        {
          tell_object(me,"����æ���أ�\n");
          return 1;
        }
	if( me->is_fighting() )
        {
          tell_object(me,"�ȴ����ˣ���˵�ɣ���\n");
          return 1;
        }

        if ((me->query("jing") < 50))
        {  
          tell_object(me,"��ľ������ܼ��У�\n");
          return 1;
        }
        if ((me->query("qi") < 50 ))
        {
          tell_object(me,"�������״̬̫��!\n");
          return 1;
        }

message_vision(HIY"\n$N��"+me->query_temp("wdhwjob") + "�����һվ��ӭ������!\n"NOR,me);
me->add("jing",-10);
me->add("qi", -5);
me->start_busy(1);
me->add_temp("wdjob",1);
if( !environment(me)->query("no_fight"))
{
if (random(10)>7)
{
obj=new(__DIR__"taishan"); 
obj->do_copy(me,maxpot,2);
obj->set("title",HIY"̩ɽ�ɵ���"NOR);
obj->set("usename",me->query("name"));
obj->move(environment(me));
message_vision(HIR"$N˵��������������������Ҫ����������Щаħ�����\n"NOR, obj);
me->kill_ob(obj);
obj->kill_ob(me);
}
else if (random(10)>7)
{
obj=new(__DIR__"henshan"); 
obj->do_copy(me,maxpot,2);
obj->set("title",HIG"��ɽ�ɵ���"NOR);
obj->set("usename",me->query("name"));
obj->move(environment(me));
message_vision(HIR"$N˵��������������������Ҫ����������Щаħ�����\n"NOR, obj);
me->kill_ob(obj);
obj->kill_ob(me);
}
else if (random(10)>7)
{
obj=new(__DIR__"hengshan"); 
obj->do_copy(me,maxpot,2);
obj->set("title",HIY"��ɽ�ɵ���"NOR);     
obj->set("usename",me->query("name"));
obj->move(environment(me));
message_vision(HIR"$N˵��������������������Ҫ����������Щаħ�����\n"NOR, obj);
me->kill_ob(obj);
obj->kill_ob(me);
}
}
if (me->query_temp("wdjob") >i && 
!me->is_fighting())
{
message_vision(HIW"$Nӭ������ʱ���Ѿ����ˣ������������ˡ�\n"NOR,me);
message_vision(HIG"$N������ɣ������콻���˱�ĵ��ӡ�\n"NOR,me,ob); 
me->start_busy(5);
call_out("destroying", 0, me);                       
}

        return 1;
}
void destroying(object me)
{   
int exp,pot;
if (!me) return;
exp=120+random(81);
pot=80+random(51);
	   tell_object(me,HIW"�㱻�����ˣ�\n" + 
                       chinese_number(exp) + "��ʵս����\n" +
                       chinese_number(pot) + "��Ǳ��\n"+
                       NOR);

        me->delete_temp("wdjob");
        me->delete_temp("wdhw");
        me->delete_temp("wdhwjob");
	me->add("combat_exp",exp);
	me->add("potential",pot);

        destruct(this_object());
}