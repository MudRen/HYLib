// Room: /d/sandboy/cook 
inherit ROOM; 
 
void create ()
{
  set ("short", "����");
  set ("long", @LONG
é�ݱ����һ�ڴ���������ʲô����,�������ڵ�,ɢ����һ����ζ,�Ա�
�������ϰ���Щ����,һֻС��Ͱ�Ͱ��������Ա�.
LONG);

  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/sansao.c" : 1,
]));
  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"yuanzi",
]));

  setup();
}
int valid_leave(object me,string dir)
{
  object ob,npc;
  ob=present("mantou",me);
  npc=present("sansao",this_object());
 if (npc&&dir=="west"&&ob)    {
   return notify_fail("����ɩ��"+me->query("name")+"��:����ͷ�㻹�ǳ����ٳ�ȥ,���˿����˲���.\n");
       }
else return ::valid_leave(me,dir);
}
 
         
           