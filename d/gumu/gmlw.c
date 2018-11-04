// Room: /u/xdd/gumu/gmlingwu.c
// Modify by river 98/08/29

#include <ansi.h>

inherit ROOM;
void create()
{
     set("short",HIC"������"NOR);
     set("long", @LONG
�˵ع������Ӵ�������֮�á����Ͻ��м������ţ�����������Ů���ڱ�Ŀ
���򡣶���ʯ������һ��͹�𣬿��Ų�������(wall), ���������һ�����ݣ�
����Щ�Źֵ�ͼ��(ground), ������һЩ��Ůͼ��(top)��
LONG
        );

      set("exits", ([
            "east" : __DIR__"liangong",
      ]));

      set("item_desc", ([
            "wall" : HIC "\t�ڹ��ķ�...��Ĺ�ӵܿ���ϰ�ڴ�. \n"NOR,
            "ground" : HIC "\t��ת��Ų֮��...��Ĺ�ӵܿ���ϰ�ڴ�.  \n"NOR,
            "top" : HIC "\t��Ů�����ڿ�,��ң����,���ΰٱ�. \n"NOR,
         ]));

     setup();
}

void init()
{
          add_action("do_yanxi", "yanxi");
}

int do_yanxi(string arg)
{
          mapping fam;
          object me;
          me = this_player();
          if ( !living(me) ) return 0;
          if (me->is_busy() || me->is_fighting())
               return notify_fail("����æ���ģ�\n");
          if (!(fam = me->query("family")) || fam["family_name"] != "��Ĺ��")
          return notify_fail("�㲻�ǹ�Ĺ���ˣ�����������Ĺ�书��\n");
          if ((int)me->query_skill("literate", 1) < 20)
          return notify_fail("��Ѿ���ֲ�ʶ,�����ɶ? \n");
          if ( arg =="wall" ){
          if ((int)me->query_skill("force", 1) > 50 )
          return notify_fail("ʯ��������������,���޷������ʲô�¶�����\n");
          if ((int)me->query("jing") < 20 )
          return notify_fail("����ú���,����˯��. \n");
          write("�㾲����ϰʯ�ڵ��ؼ������ڹ��ķ���Щ����\n");
          me->receive_damage("jing", 5 + random(15));
          me->improve_skill("force", (int)(me->query_con()/2) +
              (int)(me->query_skill("literate")/4) );
          return 1;
          }
          if ( arg =="ground" ){
          if ((int)me->query_skill("parry", 1) > 50 )
          return notify_fail("����ŵ�����ϰһ�ᣬֻ���������Ѿ������ء�\n");
          if ((int)me->query("jing") < 20)
          return notify_fail("��һ������,�������Թ���,����Ϣһ����. \n");
          write("��ģ�µ��ϵ�ͼ����������,��ϰ�м����㡣\n");
          me->receive_damage("jing", 5 + random(15));
          me->improve_skill("parry", (int)(me->query_int()/2) +
                (int)(me->query_skill("parry")/ 4 ) );
          return 1;
          }
          if ( arg =="top" ){
             message_vision(HIY"$N��ʼ���Ӷ�����Ůͼ�Ρ�\n"NOR, me);
             if ((int)me->query_skill("force", 1) < 30) {
               message_vision(HIM"$N������Ůͼ�ο�ʼ��Ѫ��ӿ, Ŀ��ֱ����,���������֮��. \n"NOR, me);
               write(HIR"�㶨������,������ͼ�������ٿ�Ϊ��. \n"NOR);
               message_vision(HIR"$N��Ȼҡ������,����������Ѫ. \n"NOR, me);
               me->receive_wound("qi", 10);
               me->unconcious();
               return 1;
               }
             if ((int)me->query_skill("dodge", 1) < 30 )
               return notify_fail("������ƽ��������Щ��Ůͼ,ȴ�������а�������. \n");
             if ((int)me->query_skill("yunv-shenfa", 1) >= 10)
               return notify_fail("����ѧ������Ů��,Ҫ����һ��,ֻ�ܿ��Լ��ڼ���ϰ. \n");
               write(HIY"�㾲����ϰ���ϵ���Ů���Σ����򵽹�Ĺ���Ṧ���ľ�������,��ʱé���ٿ���\n"NOR);
               me->improve_skill("yunv-shenfa", 10);
               write(HIR"��ϲ����λ" + RANK_D->query_respect(me)+"�����Ѿ�ѧ����Ů�����ˡ�\n"NOR);
               return 1;
               }
          return 0;
}
