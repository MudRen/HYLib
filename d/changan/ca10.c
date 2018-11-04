// This is a room made by wsl.

inherit ROOM;
void create()
{
    set("short", "������");
    set("long",@LONG
�������ʢ��������ڷ���һ���������������ǰ�ŷ���һ��
��¯�����ҷ���һЩ�������Ա߻���һ���ƾɵ����ӣ����Ϲ���һ��
ľ�ң�bian����
LONG
);
    set("no_sleep_room", "1");
    set("no_steal", "1");
    set("no_fight", "1");
    set("objects", ([
       __DIR__"obj/table" : 1,
       __DIR__"npc/shensuan" : 1,
]));
    set("exits", ([
         "east" :__DIR__"ca9",
]));
        set("item_desc", ([
    "bian" : "���е�Ϧ���������в�����ơ�
",
]));
    setup();
}

void init()
{
        add_action("do_knock","knock");
        remove_call_out("stat");
        call_out("stat", 10, this_player());
        remove_call_out("do_sleep");
        call_out("do_sleep",110+random(10));
}
int do_knock(string arg)
{
        object me,ob;
        me = this_player();
        ob = present("shensuan zi",this_object());
        if (ob){
         if(!arg || arg != "table")   return notify_fail("��Ҫ��ʲô��\n");
         if(! ob->query_temp("sleeped") )
            return notify_fail("�������Ѿ����ˣ��������������ˡ�\n");
         ob->delete_temp("sleeped");
         ob->delete("no_get");
         ob->delete("no_get_from");
         ob->enable_player();
//         ob->set("long","������Զ�������������ӡ������ɡ����ܶ��˶�Ľ����������������\n" HIY "���������ƺ�������һЩ�������ܡ�\n" NOR);
         message_vision("$N�������������ӡ�\n",me);
         message_vision("����������˯�����ʵ��۾������˸���������������Ŀ��˿�$N��\n",me);
          me->set_temp("knock", 1);
         remove_call_out("do_sleep");
         call_out("do_sleep",60);
         return 1;
        }else  return notify_fail("��õ������ɻ�����˵��\n");
}
void do_sleep()
{
      object ob;

      remove_call_out("do_sleep");
      ob=present("shensuan zi",this_object());
      if (ob && living(ob)){
      message_vision("$N���˸���Ƿ����˯���ˡ�\n",ob);
      ob->set_temp("sleeped",1);
      ob->set("no_get",1);
      ob->set("no_get_from",1);
      ob->disable_player("<˯����>");
      ob->set("long","�����������ڰ��ͷſ��������˯������Һһֱ���������ӵ��¡�\n");
      }
      
}
int stat(object me)
{
   object ob;
   
   if (!me || environment(me)!=this_object() ) return 1;   
   
   ob=present("shensuan zi",this_object());
   if (ob && ob->query_temp("sleeped")){
      message_vision("����.....��.........��...............\n",ob);
   }
   remove_call_out("stat");
   call_out("stat",60,me);
}
void reset()
{
   ::reset();
   call_out("do_sleep",0);
}

