// liangong-fu.c

inherit ITEM;
#include <ansi.h>
//int do_shouzhang();
int consider_lv(object ob,int a);
static int i = random(13)+8;
void create()
{
        set_name("����", ({ "chuan dan"}));
        set("long", "һЩ����,�����������µ���һ�㸺����˵(youshuo)����");
        set_weight(300);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("material", "paper");
                set("value", 0);
                set("unit", "Щ");
        }
        setup();
}

void init()
{
        add_action("do_shouzhang","youshuo");
}
int do_shouzhang()
{
object ob,me=this_player();
string targ;
object obj;
int maxpot,i;

if (!environment(me))  return notify_fail("���ﲻ��Ҫ������˵�ĵط�!\n");
if (me->query_temp("ryjob2/changxi") < 1)
return notify_fail("û�����ڽ������������!\n");
if (!environment(me)->query("outdoors"))
return notify_fail("�뵽�����˶�ĵط�����˵!\n");
if (environment(me)->query("outdoors") !=me->query_temp("ryjob2/where"))
return notify_fail("���ǽ��㵽"+me->query_temp("ryjob2/cx")+"ȥ����˵����!\n");
if (me->query_temp("ryjob2/done") >= 1)
{
        tell_object(me,"����������˵�ˣ���ȥ�칦�ɡ�\n");
         return 1;
}


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

        if ((me->query("jing") < 30))
        {  
          tell_object(me,"��ľ������ܼ��У�\n");
          return 1;
        }
        if ((me->query("qi") < 30 ))
        {
          tell_object(me,"�������״̬̫��!\n");
          return 1;
        }
i=random(4);
message_vision(HIY"\n$N��"+me->query_temp("ryjob2/cx") + "�ɸ�����������˵!\n"NOR,me);
if (i==0)
message_vision(CYN"\n$N˵��������Щ��ν������������������������̵Ķ���!\n"NOR,me);
else if (i==1)
message_vision(RED"\n$N˵���������һ����������������Ҳ!\n"NOR,me);
else if (i==2)
message_vision(WHT"\n$N˵��������̣��ճ�������Ψ�Ҳ���!\n"NOR,me);
else message_vision(GRN"\n$N˵��������̣�ǧ�����أ�һͳ����!\n"NOR,me);
me->add("jing",-10);
me->add("qi", -5);
me->start_busy(1);
me->add_temp("ryjob",1);
if( !environment(me)->query("no_fight"))
{
if (random(50)==1 && me->query("combat_exp") > 1000000)
{
obj=new(__DIR__"menggu"); 
obj->move(environment(me));
obj->do_copy(me,maxpot,2);
obj->set("title",HIM"�������ɻ���"NOR);
obj->set("usename",me->query("name"));
me->start_busy(1);
message_vision(HIR"����ͻȻ������һ�ˣ�\n"NOR, obj);
message_vision(HIR"$N˵����ħ�����ˣ������ڴ˺�˵�˵�����Ҫ�����е���\n"NOR, obj);
me->kill_ob(obj);
obj->kill_ob(me);
}
}

if (me->query_temp("ryjob") >i && 
!me->is_fighting())
{
message_vision(HIM"$N����˵�����������ĺܺ�,�������������������Լ�����������ʧ����\n"NOR,me);
message_vision(HIC"$N������ɣ������еĴ������������ˡ�\n"NOR,me,ob); 
me->set_temp("ryjob2/done",1);
me->start_busy(3);
call_out("destroying", 0, me);                       
}

        return 1;
}
void destroying(object me)
{   
if (!me) return;
        me->delete_temp("ryjob");
        destruct(this_object());
}
