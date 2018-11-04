// Room: /u/xdd/gumu/gmlg2.c
// Modify By River 98/08/29
#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
     set("short", HIR"������"NOR);
     set("long", @LONG
һ��ʯ�ң���״�������أ�ǰ��frontwall)խ��(backwall)����Ϊ���Σ�
��(eastwall)�߰�Բ����(westwall)��ȴ�������͡��Ҷ�ʯ���Ͽ�����㻨��
���ţ������������̳ɣ������ǳ�����޹��򡣴˴�����Ĺ�������������⹦��
LONG
        );

     set("exits", ([
         "north" : __DIR__"gmlg1",          
         "south" : __DIR__"gmlg3",          
     ]));

     setup();
}

void init()
{
         add_action("do_xiulian", "xiulian");
         add_action("do_yanxi", "yanxi");
         add_action("do_tui","tui");
}

int do_yanxi(string arg)
{
          mapping fam;
          object me = this_player();
          if (!(fam = me->query("family")) || fam["family_name"] != "��Ĺ��")
           return notify_fail("�㲻�ǹ�Ĺ���ˣ�����������Ĺ�书��\n");
          if (me->is_busy() || me->is_fighting())
               return notify_fail("����æ���ģ�\n");
          if ((int)me->query_skill("literate", 1) < 30)
          return notify_fail("��Ѿ���ֲ�ʶ,�����ɶ? \n");            
          if (arg == "top"){
          if (me->query("gender") == "Ů��")
             return notify_fail("ȫ�潣��������֮�������ʺ�Ů����ϰ��\n");
          if ((int)me->query_skill("sword", 1) < 20)
            return notify_fail("���������̫��޷���ϰȫ�潣����\n"); 
          if (me->query_skill("quanzhen-jian", 1) >= 1)
             return notify_fail("���Ѿ�ѧ��ȫ�潣�����Լ��ú����ɡ�\n");      
          write("�������Ҷ���ͼ�ƣ����д�Ħȫ�潣���ľ���֮����\n");
          me->receive_damage("jing", 5);
          me->receive_damage("jing",15);
          me->improve_skill("quanzhen-jian", 2);
          return 1;
         }
       return 1;
}

int do_xiulian(string arg)
{
          mapping fam;
          object me = this_player();
          if (!(fam = me->query("family")) || fam["family_name"] != "��Ĺ��")
               return notify_fail("�㲻�ǹ�Ĺ���ˣ�����������Ĺ�书��\n");
          if (me->is_busy() || me->is_fighting())
               return notify_fail("����æ���ģ�\n");          
          if (me->query("jing") < 20)
               return notify_fail("�㾫�����ܼ���,ȥ����ЪϢ��. \n");
          if ((int)me->query_skill("literate", 1) < 30)
          return notify_fail("��Ѿ���ֲ�ʶ,�����ɶ? \n");
          if (arg == "frontwall"){
          write("����������ǰ��խխ��ʯ�ڣ���һ���������������ֱ�һ�����顣\n");
          if (me->query_skill("strike", 1) > 50)
          return notify_fail("�������ۻ룬���������������ˡ�\n");
          me->receive_damage("jing", 5 + random(15));
          me->improve_skill("strike", (int)(me->query_int()/3) +
              (int)(me->query_skill("strike")/4));
          return 1;
          }
          if (arg == "backwall"){
          write("���ȭֱ�����ͺ�ڣ�ʯ���Ľ�,��Ҳ���Լ����;�����������\n");
          if (me->query_skill("cuff", 1) > 50)
          return notify_fail("��ȭ���Ѹ����ޱȣ�ȴ����������\n");
          me->receive_damage("jing",5 + random(15));
          me->improve_skill("cuff", (int)(me->query_int()/3) +
               (int)(me->query_skill("cuff",1)/ 4));
          return 1;
          }
          if (arg == "eastwall"){
          write("���ƶ���ʯ��̤�Ž��������Ĵ�Ħ���Ͻ������衣\n");
          if (me->query_skill("sword", 1) > 50)
          return notify_fail("���ʯ��������������ȫȻ����,�����ٷ�����. \n");
          me->receive_damage("jing", 5 + random(15));
          me->improve_skill("sword", (int)(me->query_int()/3) +
               (int)(me->query_skill("sword", 1)/4) );
          return 1;
          }
          if (arg == "westwall"){
          write("��������ָ,���������������ʯ��,ϸ�Ĳ����������շ�����. \n");
          if (me->query_skill("throwing", 1) > 50 )
          return notify_fail("�㰵���շ�����,�ٲ�������ڴ�. \n");
          me->receive_damage("jing", 5 + random(15));
          me->improve_skill("throwing", (int)(me->query_int()/3) +
                 (int)(me->query_skill("throwing", 1)/4 ));
          return 1;
          }
     return 0;
}

int do_tui(string arg)
{
          mapping fam; 
          object me=this_player();
          if (me->is_busy() || me->is_fighting())
               return notify_fail("����æ���ģ�\n");
          if ( arg == "eastwall"){  
          if (!(fam = me->query("family")) || fam["family_name"] != "��Ĺ��")
               return notify_fail("�㲻�ǹ�Ĺ���ˣ����ܽ����Ĺ���ң�\n");
           message_vision(YEL"$N���ֵ���Բ�Ļ������˼��£�һ���ʯ�����ƿ����ֳ�һ�ȶ��š�\n"NOR,me);
           set("exits/enter", __DIR__"gmlg3");            
	   me->receive_damage("qi", 30); 
           remove_call_out("close");
           call_out("close", 5, this_object());    
           return 1;
           }
        return notify_fail("��Ҫ��ʲô��\n");
}

void close(object room)
{
        message("vision",HIY"��ʯ�����˻���ԭλ���ֵ�ס����ڡ�\n"NOR, room);
        room->delete("exits/enter");
}
