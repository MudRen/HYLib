// Room: /d/sandboy/zizhuan
inherit ROOM;

void create ()
{
  set ("short", "������");
  set ("long", @LONG
�����е�һ��С���֣�ͨ����ɵ���ɫ�������ܵĻ�����Ϊһ�壬��
�����������������໥ײ������
LONG);

  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/laonigu.c" : 1,
]));
set("outdoors","/d/jiangnan");
  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"zhulin4",
  "enter" : __DIR__"inzizhuan",
]));

  setup();
}
int valid_leave(object me,string dir)
{
  object ob;
 ob=present("dubi shenni",this_object());
 if (objectp(ob)&&dir=="enter")  {
       if (ob->query("banghui")!=me->query("banghui"))  {
   message_vision("$N˫��һ��,��$n������λʩ����������.\n",ob,me);
     return notify_fail("");
                  }  
        }
return ::valid_leave(me,dir);
}
  
