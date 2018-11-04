// Room: /u/xdd/gumu/gmqinroom.c
// Modify By River 98/08/30
#include <ansi.h>;
inherit ROOM;
#include <room.h>
void create()
{
          set("short", HIC"����"NOR);
          set("long", @LONG
һ��ʯ��(table)��һ��ʯ�ʣ����Ϸ���һ�ѹ���(qin)����С��Ů���ʱ
�̸����㻳�ĵط���ÿÿ����������ƽ����ͣ�ֱ�����ĳ�����������������
LONG        );

          set("exits", ([
               "west" : __DIR__"houting", 
          ]));

          set("item_desc", ([
                "qin" : HIC"����һ�������Զ�Ĺ��٣��ٷ���ӣ�����������
���Ͽ���[ ��Զ ���� �ɷ� ] �����֡�\n"NOR,
                "table" : "���Ϸ���һ�ѹ��١� \n",
                  ]));
//          create_door("east", "ʯ��", "west", DOOR_CLOSED);
          setup();
}

void init()
{
          add_action("do_tan", "tan");
          add_action("do_nuo", "nuo");
          add_action("do_yanxi","yanxi");
}

int do_tan(string arg)
{
          mapping fam;
          object me = this_player();

          if (arg == "qin"){
          if (!(fam = me->query("family")) || fam["family_name"] != "��Ĺ��")
           return notify_fail("�㲻�ǹ�Ĺ���ˣ�����������Ĺ�书��\n");
          if (me->query("qi") < 30 || me->query("jing") < 30)
           return notify_fail("�㾫��к�, ��ȥЪϢһ���������ٰɡ�\n");
          write(HIC"���Ŀ����һ����Ϣ, ���������ĸ��ٶ�����\n"NOR);
          if (me->query_skill("force", 1) < 50 )
          return notify_fail("�㵯�˰���, ��������ѻ��, �㻹�ǵ��޻�ȥ�ɡ�\n");
          if (me->query_skill("force", 1) > 100){
          message_vision(HIC"$N�������ߣ������پ�����������������������\n"BLINK HIY"
\t�׺�һ��Ц ����������
\t�������� ֻ�ǽ�
\t����Ц �׷����ϳ�
\t˭��˭ʤ�� ��֪��
\t��ɽЦ ����ң
\t�����Ծ� �쳾�������ཿ
\t���Ц ���Ǽ���
\t���黹ʣ��һ������
\t����Ц ���ټ���
\t�������� �ճ�ЦЦ\n"NOR,me);
           return 1;
           }
//        return notify_fail("���ڹ���տ, ����������������������. \n");
          write("����������, �����پ�, ��������ƽ��, ����������Ȼ������\n");
          me->receive_damage("qi", 15+random(10), me);
          me->receive_damage("jing", 15+random(10), me);
          me->improve_skill("force", (int)(me->query_con()/4) +
                        (int)(me->query_skill("force", 1)/4) );
          return 1;
          }
          write("��Ҫ��ʲô? ���޻�? \n");
      return 1;
}

int do_nuo(string arg)
{
         object me = this_player();
         if (arg == "qin"){
         message_vision(YEL"$N�����Ų���˹��١�\n"NOR, me);
         write(HIC"���µ������Ͼ�Ȼ����һƪ���֡�\n"NOR);
         me->set_temp("marks/qin", 1);
         return 1;
         }
         return notify_fail("��ҪŲʲô? \n");
}

int do_yanxi(string arg)
{
         mapping fam;
         object me = this_player();
         if (arg == "table"){
         if (me->query_temp("marks/qin")){
         if (me->query("potential", 1) < 1)
             return notify_fail("���Ǳ��û�ˣ������ټ�����ϰ��\n");
         if (!(fam = me->query("family")) || fam["family_name"] != "��Ĺ��")
          return notify_fail("�㲻�ǹ�Ĺ���ˣ�����������Ĺ�书��\n");
         if (me->query("qi") < 40 )
          return notify_fail("��ľ���ܲ�, ����ȥ��Ϣһ��. \n");           
         if (me->query_skill("force", 1) < 40)
          return notify_fail("��Ļ����ڹ�̫�ͣ��޷���ϰ���߼����ڹ���\n");        
         if (me->query_skill("yunv-xinfa", 1) < 50)
          return notify_fail("�����Ů�ľ��ȼ�̫�ͣ��޷��������ϵ����֡�\n");
         if (me->query_skill("yunv-xinfa", 1) > 100)
          return notify_fail("�����Ů�ľ�����һ�㣬����˫�˺�����Ů���ˡ�\n");
         write("�㿪ʼ��ϰ���ϵ���Ů�ľ���\n");
         me->improve_skill("yunv-xinfa", (int)(me->query_int()/2) +
                           (int)(me->query_con()/2) );
         me->receive_damage("qi", 15 + random(20));
         me->add("potential", -1);
         return 1;
         }
        return notify_fail("��������ϵĹ����о���һ������������ֵǮ��\n");
     }
    return notify_fail("��Ҫ��ϰʲô��\n");
}
