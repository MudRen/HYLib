// liangong-fu.c

inherit ITEM;
#include <ansi.h>
//int do_shouzhang();
int consider_lv(object ob,int a);
static int i = random(9)+3;
void create()
{
        set_name("���չ�����", ({ "lj lingpai"}));
        set("long", "һ�����չ�����,�������ĵ���һ�㸺���ֹ�Ʒ����(shougongpin)");
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
        add_action("do_shouzhang","shougongpin");
}

int do_shouzhang(string arg)
{
object ob,me=this_player(),obj,obn;
string targ;
int maxpot;
if (!arg||!ob=present(arg,environment(me)))
               return notify_fail("��Ҫ��˭�չ�Ʒ��\n");
if(!me->query_temp("ljjob2"))
return notify_fail("�㲻����������������\n");
targ=ob->query("name");
if (userp(ob))
return notify_fail("�����������!\n");
if ( ob->query("family/family_name") != me->query_temp("ljjob2") )
return notify_fail("���ǽ�����"+me->query_temp("ljjob2")+"�ֹ�Ʒ������!!\n");
if (this_object()->query("usename")!=me->query("name"))
return notify_fail("�ⲻ���������!!\n");
if( !living(ob))
return notify_fail("�˼��������أ�\n");
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
        if (ob->query("combat_exp")*2/3 > me->query("combat_exp"))
        {  
          tell_object(me,"�Ǹ����书��������ߵĶ࣬����Ҫ��̫�ðɣ�\n");
          return 1;
        }
        if (ob->query("startroom") != base_name(environment(ob)))
        {  
          tell_object(me,"�Ǹ���˵��������������Ȼᣬ������ȥ�ٸ��㣡\n");
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

message_vision(HIC"\n$N��$n˵������Ϊͯ��׼���Ķ�������û��?\n"NOR,me,ob);
message_vision(HIG"\n$nһ�������չ���$N����˵������Ʒ�Ѿ�׼�����ˡ�������$Nһ�������  ��\n"NOR,me,ob);
                        me->add("jing",-me->query("jing")/10);
                        me->add("qi", -me->query("qi")/10);
                        me->start_busy(6);

message_vision(HIW"$N���˿���$n˵,����������\n"NOR,me,ob);
message_vision(HIG"$N�����Ƹ���$n��\n$N˵������������ҩ�������ȥ���\n"NOR,me,ob); 
          obn=new(__DIR__"gongpin");
          obn->set("ljby",me->query("name"));
          obn->move(me);

        destruct(this_object());
        return 1;

}
