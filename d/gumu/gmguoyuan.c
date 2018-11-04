// Room: /u/xdd/gumu/guoyuan.c
// Modify by river 98/08/29
#include <ansi.h>;
inherit ROOM;

void create()
{
     set("short", HIG"��԰"NOR);
     set("long", @LONG
ת��ɽ��������һ��Ƭ���֡�һ�ÿù������øߴ�ïʢ��֦Ҷ���ܣ�����
�ʹ���guo)���������ˡ�����Ҷ��ɳɳ���죬������Ⱥ�������ҡ���裬��
��������㣬��������Դ��ı���һ���ˡ���������������ž�������
�䡣���ӱ��ϴӵص���ӿ��һ����Ȫ��quan����
LONG        );
     
     set("outdoors","��Ĺ");
     
     set("exits", ([
         "east" : __DIR__"caodi",
"west" : __DIR__"huacong",
     ]));

     set("item_desc", ([
          "guo" : "�����ʹ�����֦ͷ��������Բɣ�cai��������\n",
          "quan" : "һ���Ȫ�峺���ף����̲�ס��ȥ�ȣ�he�����ڡ�\n",
     ]));
    
     setup();
}

void init()
{
   add_action("do_cai", "cai");
   add_action("do_he", "he");
   add_action("do_zhao","zhao");
}

int do_cai(string arg)
{
       object ob,me = this_player();
      if (arg == "guo") {
       if(objectp(ob = present("ye guo", me))) 
           return notify_fail("�㲻���Ѿ����ˣ��������ٲɰɡ�\n");   
       message_vision(YEL"$N���ִ�����ժ��һ��Ұ����\n"NOR, me);
       new(__DIR__"obj/guo")->move(me);
       return 1;
       }
     return notify_fail("��Ҫ��ʲô? \n");
}

int do_he(string arg)
{
    object me = this_player();
       if (arg == "quan") {
          if (me->query("water") < me->query("str")*10+100) {
            message_vision(HIC"$N����һ����Ȫ�������غ���һ�ڡ�\n"NOR, me);
            me->add("water", 50, me);
            return 1;
           }
       return notify_fail("���̫���ˣ����³�����\n");  
       } 
      return notify_fail("��Ҫ��ʲô��\n");
}

int do_zhao(string arg)
{
          mapping fam;
          object me = this_player();
          if (!(fam = me->query("family")) || fam["family_name"] != "��Ĺ��")
           return notify_fail("�㲻�ǹ�Ĺ���ˣ�����������Ĺ�书��\n");
          if (me->is_busy() || me->is_fighting())
               return notify_fail("����æ���ģ�\n");                      
          if (arg == "quan"){   
          if (me->query("gender") == "����")
             return notify_fail("�����˶����Լ��ĵ�Ӱ��ʲô�࿴�ġ�\n");       
          if ((int)me->query_skill("cuff", 1) < 20)
            return notify_fail("�����Ȫˮ����Ū�˵ؿ��˰��죬�е�·����͵ĸо���\n"); 
          if (me->query_skill("meinv-quan", 1) >= 10)
             return notify_fail("���Ѿ�ѧ����Ůȭ�����Լ��ú����ɡ�\n");      
          write("��ġ���Լ�ˮ�еĵ�Ӱ������������ᡣ\n");
          me->receive_damage("jing", 15);
          me->improve_skill("meinv-quan", 2);
          return 1;
         }
       return 1;
}
