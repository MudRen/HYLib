// liangong-fu.c

inherit ITEM;
#include <ansi.h>
//int do_shouzhang();
int consider_lv(object ob,int a);
static int i = random(9)+3;
void create()
{
        set_name("���������", ({ "lx lingpai"}));
        set("long", "һ�����������,�������ĵ���һ�㸺��������huwei");
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
        add_action("do_shouzhang","huwei");
}
int do_shouzhang()
{
object ob,me=this_player();
string targ;
object obj;
int maxpot;
if (!environment(me))  return notify_fail("���ﲻ��Ҫ�㻤���ĵط�!\n");
if (environment(me)->query("short") !=me->query_temp("lxhwjob"))
return notify_fail("���ǽ��㵽"+me->query_temp("lxhwjob")+"ȥ������!\n");
if(!me->query_temp("lxhw"))
return notify_fail("�㲻�����������������\n");
if (this_object()->query("usename")!=me->query("name"))
return notify_fail("�ⲻ��������������!!\n");

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

message_vision(HIW"\n$N��"+me->query_temp("lxhwjob") + "�����߶���Ѱ�ҵ���!\n"NOR,me);
me->add("jing",-10);
me->add("qi", -5);
me->start_busy(1);
me->add_temp("lxjob",1);
if( !environment(me)->query("no_fight"))
{
if (random(10)>7)
{
obj=new(__DIR__"shaolin"); 
obj->do_copy(me,maxpot,2);
obj->set("title",HIW"�����ɵ���"NOR);
obj->set("usename",me->query("name"));
obj->move(environment(me));
message_vision(HIY"$N��Ц����������Ҫ��ʶ��ʶ������������ʲô����?\n"NOR, obj);
me->kill_ob(obj);
obj->kill_ob(me);
}
else if (random(10)>7)
{
obj=new(__DIR__"emei"); 
obj->do_copy(me,maxpot,2);
obj->set("title",HIG"�����ɵ���"NOR);
obj->set("usename",me->query("name"));
obj->move(environment(me));
message_vision(HIY"$N��Ц����������Ҫ��ʶ��ʶ������������ʲô����?\n"NOR, obj);
me->kill_ob(obj);
obj->kill_ob(me);
}
else if (random(10)>7)
{
obj=new(__DIR__"wudang"); 
obj->do_copy(me,maxpot,2);
obj->set("title",HIY"�䵱�ɵ���"NOR);     
obj->set("usename",me->query("name"));
obj->move(environment(me));
message_vision(HIY"$N��Ц����������Ҫ��ʶ��ʶ������������ʲô����?\n"NOR, obj);
me->kill_ob(obj);
obj->kill_ob(me);
}
}
if (me->query_temp("lxjob") >i && 
!me->is_fighting())
{
message_vision(HIW"$N����ʱ���Ѿ����ˣ������������ˡ�\n"NOR,me);
message_vision(HIG"$N������ɣ������ƽ����˱�ĵ��ӡ�\n"NOR,me,ob); 
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
pot=90+random(61);
	   tell_object(me,HIW"�㱻�����ˣ�\n" + 
                       chinese_number(exp) + "��ʵս����\n" +
                       chinese_number(pot) + "��Ǳ��\n"+
                       NOR);
        me->delete_temp("lxjob");
        me->delete_temp("lxhw");
        me->delete_temp("lxhwjob");
 	me->add("combat_exp",exp);
	me->add("potential",pot);
        destruct(this_object());
}