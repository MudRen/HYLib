//Cracked by Roath
#include <ansi.h>
#include <command.h>
inherit ITEM;
void create()
{
        set_name(YEL "����" NOR, ({ "qu pu", "pu"}));
        set_weight(1000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "
һ���Ѷ����������ף�����Գ�(chang)��������ӣ�

������ڣ�����ġ�(xiangzhong)
�������ɸ衷(dongxian_ge)
����������������ʡ�(maipo_tang)
������˹С����(bosi_xiaoqu)
����Ц��������(xiaoao_jianghu)
����ɽ����(shanpo_yang)
������������(dielian_hua)
������ɣ�ӡ�(caisang_zi)
���������(wusu_nian)   
�������ɸ衷(dongxian_ge)
������ɣ�ӡ�(caisang_zi)
  ����̨��(san_tai)
  �������С�(yujie_xing)
  �����ޡ�(zuichui_bian)
  ��ˮ����ͷ��(shuidiao_getou)
  ��ԲԲ����(yuanyuan_qu)
  ����������(wanghai_chao)
  ��������  ��Ϊ���(wenshi_jian)
  ����������(dielian_hua)
  �������ǿ��С�(yinma_changcheng)
  ����������ҹ��(chunjiang_huayueye)
  �������ơ�(jiangjin_jiu)
  ��Ц��������(xiaoao_jianghu)
  �������ˡ�(yu_meiren)
  ����ѩ�������йٻؾ���(baixue_ge)
  
��������ó��ò��ã�����ͣ(ting)�£��ٻ�ȥ������
\n");
                set("value", 0);
                set("material", "silk");
             }
        setup();
}

void init()
{
        add_action("do_sing", "chang");
        add_action("do_halt", "ting");
}
#include "sing.c";

int do_halt()
{
        if (find_call_out("sing_stage") < 0) return 0;
        message_vision(HIR"\n$N���ִ��һ��ʹ��ı��飬���εؿ�����������ͣ����������\n"NOR, this_player());
        remove_call_out("sing_stage");
        return 1;
}

int do_sing(string arg)
{
       object me, ob,ob1; 
       int i = sizeof(qupu);
       int stage;
        string st1,st2,song;
   mapping myfam, vtfam;
       stage = 0;
       me = this_player();
       ob = this_object();
       if (find_call_out("sing_stage") >= 0) return notify_fail("����ͬʱ������������\n");
        if (!arg || arg=="") return notify_fail ("����Ϊ˭��ʲô����\n");

        if (sscanf( arg,"%s %s",st1,st2)!=2 )
           return notify_fail ("chang <ĳ��> <����>\n");

        if (!ob1=present(st1,environment(this_player())))
          return notify_fail("�Ҳ��� "+st1+" �������.\n");

if (environment(me)->query("sleep_room"))
                return notify_fail("�����ﳪ�裬��Ӱ�������Ϣ��\n");

if( environment(me)->query("no_beg") &&
      environment(me)->query("no_fight") &&
       environment(me)->query("no_steal")) 
          return notify_fail(HIY"\n��ҪӰ����ˣ�������һ����ĵط��ɡ�\n"NOR);

        if ( (!( myfam= me->query("family")) || myfam["family_name"] != "��ң��"))
          return notify_fail("ֻ����ң�ɵ��Ӳ�������ʸ�\n");
if( !ob1->is_character()
|| !living(ob1))
return notify_fail("ֻ�ܶ������˵��ٳ��衣\n");

    if (me->query("gender")=="����" && ob1->query("gender") !="Ů��" ) 
          return notify_fail("��һ�������ˣ�Ϊһ�������˵��ٳ���?�.\n");
    if (me->query("gender")=="Ů��" && ob1->query("gender") !="����" ) 
          return notify_fail("��һ����������Ĺ��ﵯ�ٳ���?�.\n");

song=st2;
me->set_temp("singn",st1);
       if(!arg) return notify_fail("���볪ʲô��\n");
        while (i--) if (song == qupu[i]["name"]) break;
        if (i<0) return notify_fail("�����ﻹû�����볪�����ӡ�\n");
        if(me->is_busy())
           return notify_fail("����æ���ء�\n");
        message_vision(HIG"$N��$n���˵�ͷ��\n\n"NOR,me, ob1);
        message_vision(HIG"$N������ٷ��ڻ��������ıߵ��߳����������������������������ף����˲����������С�\n\n"NOR,me, ob);
if (me->query_temp("singsong"))
{
if (qupu[i]["name"]!=me->query_temp("singsong"))
{
message_vision(HIW"���ǽ�$N��ϰ"+me->query_temp("singsong")+"����?\n"NOR, me);
}
}
      call_out("sing_stage", 2, me, stage, i, sizeof(qupu[i]["context"]));
      return 1;
}

void sing_stage(object me, int stage, int i, int size)
{
object ob1;
        int b1,b2;
if (!me)return;
   if(stage < size) {
            tell_object(me,qupu[i]["context"][stage]);
//   message_vision(qupu[i]["context"][stage], me);
   me->start_busy(1);
if (me->query("combat_exp") >1000000)
   call_out("sing_stage", 3, me, ++stage, i, size);
else    call_out("sing_stage", 1, me, ++stage, i, size);
   }
   else {
         message_vision(HIG"\n����һ�ᣬ$N���������������ᣬ�ƺ���ˮ����Զȥ�����ڸ������գ���Ȼ������\n"NOR, me);
if (!me)return;
if (!environment(me)) return;
        if (!ob1=present(me->query_temp("singn"),environment(this_player())))
{
message_vision(HIY"��$N��������ˣ�����$N�ǰ�æ��!\n\n"NOR,me);
          return notify_fail(HIY"�����������ˣ��������ǰ�æ��.\n"NOR);
}
if (qupu[i]["name"]==me->query_temp("singsong"))
{
        if (!ob1=present(me->query_temp("singn"),environment(this_player())))
{
message_vision(HIY"��$N��������ˣ�����$N�ǰ�æ��!\n\n"NOR,me);
          return notify_fail(HIY"�����������ˣ��������ǰ�æ��.\n"NOR);
}
b1=ob1->query("per");
b2=ob1->query("per")*2/3;
if (!b1) b1=20;
if (!b2) b1=10;
if (b1 >62) b1=62;
if (b2 >50) b2=50;
b1=random(b1);
b2=random(b2);

me->add("combat_exp", 12+b1);
me->add("potential", 8+b2);
message_vision(HIG"$n���˺��Ŀ����ơ���$N΢΢һЦ!\n\n"NOR,me, ob1);
message_vision("$N�ľ������"+chinese_number(12+b1)+"�㡣\n", me);
message_vision("$N��Ǳ�ܼ���"+chinese_number(8+b2)+"�㡣\n", me);
me->delete_temp("singsong");
me->delete_temp("singn");
}
    }
}