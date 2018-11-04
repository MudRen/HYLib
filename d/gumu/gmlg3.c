// Modify By River 98/08/29
#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
     set("short", HIR"������"NOR);
     set("long", @LONG
��������һ�ң�ȴ����һ�䴦���Գƣ����ִ����෴�����Ǻ�խǰ����Բ��
�ǣ��Ҷ�Ҳ�ǿ������������š��˴����ǹ�Ĺ����ʦ�ֳ�Ӣ���书֮�ء�
LONG
     );      
     set("exits", ([
         "north" : __DIR__"gmlg2",          
         "south" : __DIR__"gmlg4",          
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
          if (me->query("gender") == "����")
             return notify_fail("��Ů����������֮�������ʺ�������ϰ��\n");
          if ((int)me->query_skill("sword", 1) < 20)
            return notify_fail("���������̫��޷���ϰ��Ů������\n"); 
          if (me->query_skill("yunv-jian", 1) >= 1)
             return notify_fail("���Ѿ�ѧ����Ů�������Լ��ú����ɡ�\n");      
          message_vision("$N�����Ҷ���ͼ�ƣ����д�Ħ��Ů�����ľ���֮����\n", me);
          me->receive_damage("jing", 5);
          me->receive_damage("jing",15);
          me->improve_skill("yunv-jian", 2);
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
          if (me->query("jing") < 40)
               return notify_fail("�㾫�����ܼ���,ȥ����ЪϢ��. \n");
          if ((int)me->query_skill("literate", 1) < 30)
          return notify_fail("��Ѿ���ֲ�ʶ,�����ɶ? \n");
          if (arg == "backwall"){
          write("�����������խխ��ʯ�ڣ���һ���������������ֱ�һ�����顣\n");
          if (me->query_skill("strike", 1) < 50)
          return notify_fail("�㿴�˰���ֻ��Ī����ʲôҲû��ѧ�ᡣ\n");
          if (me->query_skill("strike", 1) > 100)
          return notify_fail("�������ۻ룬���������������ˡ�\n");          
          me->receive_damage("jing", 10 + random(20));
          me->improve_skill("strike", (int)(me->query_int()/3) +
              (int)(me->query_skill("strike")/4));
          return 1;
          }
          if (arg == "frontwall"){
          write("���ȭֱ������ǰ�ڣ�ʯ���Ľ�,��Ҳ���Լ����;�����������\n");
          if (me->query_skill("cuff", 1) < 50)
          return notify_fail("�㿴�˰���ֻ��Ī����ʲôҲû��ѧ�ᡣ\n");
          if (me->query_skill("cuff", 1) > 100)
          return notify_fail("��ȭ���Ѹ����ޱȣ�ȴ����������\n");
          me->receive_damage("jing",10 + random(20));
          me->improve_skill("cuff", (int)(me->query_int()/3) +
               (int)(me->query_skill("cuff",1)/ 4));
          return 1;
          }
          if (arg == "westwall"){
          write("��������ʯ��̤�Ž��������Ĵ�Ħ���Ͻ������衣\n");
          if (me->query_skill("sword", 1) < 50)
          return notify_fail("�㿴�˰���ֻ��Ī����ʲôҲû��ѧ�ᡣ\n");
          if (me->query_skill("sword", 1) > 100)
          return notify_fail("���ʯ��������������ȫȻ����,�����ٷ�����. \n");
          me->receive_damage("jing", 10 + random(20));
          me->improve_skill("sword", (int)(me->query_int()/3) +
               (int)(me->query_skill("sword", 1)/4) );
          return 1;
          }
          if (arg == "eastwall"){
          write("��������ָ,���Ŷ����������ʯ��,ϸ�Ĳ����������շ�����. \n");
          if (me->query_skill("throwing", 1) < 50)
          return notify_fail("�㿴�˰���ֻ��Ī����ʲôҲû��ѧ�ᡣ\n");
          if (me->query_skill("throwing", 1) > 100 )
          return notify_fail("�㰵���շ�����,�ٲ�������ڴ�. \n");
          me->receive_damage("jing", 10 + random(20));
          me->improve_skill("throwing", (int)(me->query_int()/3) +
                 (int)(me->query_skill("throwing", 1)/4 ));
          return 1;
          }
     return 0;
}

int do_tui(string arg)
{          
          object me=this_player();
          if (me->is_busy() || me->is_fighting())
               return notify_fail("����æ���ģ�\n");
          if ( arg == "westwall"){  
           message_vision(YEL"$N���ֵ���Բ�Ļ������˼��£�һ���ʯ�����ƿ����ֳ�һ�ȶ��š�\n"NOR,me);
           set("exits/out", __DIR__"gmlg2");            
          me->receive_damage("qi", 30); 
           remove_call_out("close");
           call_out("close", 5, this_object());    
           return 1;
           }
        return notify_fail("��Ҫ��ʲô��\n");
}

void close(object room)
{
        message("vision",HIY"��ʯ�����˻���ԭλ���ֵ�ס�˳��ڡ�\n"NOR, room);
        room->delete("exits/out");
}

