 /*Copyright (C) 1998 Apstone, Inc. */
inherit ROOM;
void create()
{
        set("short", "���");
        set("long", @LONG
���λ����ɽ֧�������ڳ�ɽ��´�е�ɽ���ɴ������й���������
�����ߴ�ͦ�ε�������������������˵�������ֵĹ�ľ���ʻ���������
���£����ﻹ�������ޱȣ����˸е������泩��
LONG
        );
        set("exits", ([ 
  "north" : __DIR__"chairong",
  "south" : __DIR__"bingchuan",
  "east" :  __DIR__"goudi",
])); 
   set("item_desc", ([
      "��ľ": "һ�Ӳ�֪���Ĺ�ľ��������ï�ܡ�\n",
      "guanmu": "һ�Ӳ�֪���Ĺ�ľ��������ï�ܡ�\n",
      "����": "�Ұ�ɫ���������Ͻ�����һ�������۾��Ƶİ̺ۣ��е�����Ц����
�����ڿޣ������е�һ����Ŀ���ƺ�������һ�Թ�ľ�ϡ�\n",
      "yangshu":"�Ұ�ɫ���������Ͻ�����һ�������۾��Ƶİ̺ۣ��е�����Ц����
�����ڿޣ������е�һ����Ŀ���ƺ�������һ�Թ�ľ�ϡ�\n",
   ]) );
        //set("no_pk",1);
        
        
        set("outdoors", "xinjiang");
        set("coor/x",-1110);
        set("coor/y",2020);
        set("coor/z",0);
        setup();
} 
void init()
{
   add_action("do_look", "look");
} 
int do_look(string arg)
{
   object me; 
   me = this_player(); 
   if (!arg || (arg != "����" && arg != "yangshu")) return 0;
   tell_object(me, "�Ұ�ɫ���������Ͻ�����һ�������۾��Ƶİ̺ۣ��е�����Ц����
�����ڿޣ������е�һ����Ŀ���ƺ�������һ�Թ�ľ�ϡ�\n");
//   me->set_temp("marks/foundjade", 1);
   return 1; 
} 
void dig_notify()
{
   object me, box;
   int llvl;
    if(query("already")) return 0; 
   me = this_player();
   llvl = (int)me->query("kar"); 
   box = present("iron box", this_object());
   if(random(100) < llvl) {
      message_vision("��������һ����$N�ĸ��ƺ�������һ���������ϡ�\n", me);
      tell_object(me, "��ͷһ����������¶����һ�����С�\n");
      if(!objectp(box)) {
         box = new(__DIR__"obj/box");
         box->move(this_object());
        set("already",1);
      }
   }
   else {
      message_vision("���ϳ�����һ�����ӣ����˸����֦Ҷ��$Nʲô��û�з��֡�\n",me);
   }   
}   
