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
       object me, ob; 
       int i = sizeof(qupu);
       int stage;
       stage = 0;
       me = this_player();
       ob = this_object();
//       if(me->query("id") != "xqin")
//       return notify_fail("����ĥ�˰��죬���ǰ��Ҳ����������\n");
       if (find_call_out("sing_stage") >= 0) return notify_fail("����ͬʱ������������\n");
       if(!arg) return notify_fail("���볪ʲô��\n");
        while (i--) if (arg == qupu[i]["name"]) break;
        if (i<0) return notify_fail("�����ﻹû�����볪�����ӡ�\n");
        if(me->is_busy())
           return notify_fail("����æ���ء�\n");
//        if(me->query("gender") != "����"){
//
        if(present("zhu xiao", me))
        message_vision(HIG"$N��������ŵ��������Ĵ����������������������������ף����˲����������С�\n\n"NOR,me, ob);
          else message_vision("$N����$n���ſ����ѽѽѽ����������\n\n"NOR, me, ob);
//          }
      call_out("sing_stage", 2, me, stage, i, sizeof(qupu[i]["context"]));
      return 1;
}

void sing_stage(object me, int stage, int i, int size)
{
   if(stage < size) {
   message_vision(qupu[i]["context"][stage], me);
   me->start_busy(1);
   call_out("sing_stage", 1, me, ++stage, i, size);
   }
   else {
      if(present("zhu xiao", me))
         message_vision(HIG"\n����һ�ᣬ$N���������������ᣬ�ƺ���ˮ����Զȥ�����ڸ������գ���Ȼ������\n"NOR, me);
      else message_vision("\n$N�������һ�֣�����һ����Х��Х��ԶԶ���˿�ȥ��\n", me);
    }
}