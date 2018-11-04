// Room: lwhole.c

#include <ansi.h>;

inherit ROOM;

void create()
{
     set("short", "ʯ���Ҷ�");
     set("long", @LONG
����һ��Ȼʯ�������Ǻ����̫������ʱ��ֱ��ȫ��������������
��ס����������һʯ������߷���һЩʯ�룬�����ʯ��(wall)ʮ��ƽ����
LONG
        );
     set("exits", ([
         "out" : __DIR__"wanniansong",
             ]));    
     set("item_desc", ([
          "wall" : HIW "  ......��֮��������֮Ƥë����֮������˹��˫��֧�ţ�һ����ͨ��
���������飬������ȥ�����������飬������ȥ......\n"NOR,
             ]));
     set("no_fight", 1);
     setup();
}

void init()
{
     add_action("do_study", "study");
}

int do_study(string arg)
{
     object me;
     me = this_player();

     if ( !living(me) ) return 0;

     if ((int)me->query_skill("literate", 1) < 10)
      {  write("����Ҳ����ʶ����,����ж������ķ���\n");
        return 0;
      }
     if ( arg =="wall" )
  {
     if( !SKILL_D("taiji-shengong")->valid_learn(me) ) {
	write("����Ŀǰ��������û�а취ѧϰ���ּ��ܡ�\n");
	return 1;
     }
     message_vision("$N��ʼ�����ĥ��\n", me);
     if ( (int)me->query("jing")<50) 
      { write("��̫���ˣ�����Ъ�����ж��ɣ�\n");
        return 1;
      }
     if ((int)me->query_skill("taiji-shengong", 1) >= 101)
     {write("�����ʯ����ϰһ�ᣬֻ���������Ѿ������ء�\n");
      return 1;
     }
     write("�㾲����ϰʯ���ϵ��ؼ������ڹ��ķ���Щ����\n");

     me->receive_damage("jing", 40);
     me->improve_skill("taiji-shengong", (int)me->query("int"));
     return 1;
   }

     return 0;
  }
