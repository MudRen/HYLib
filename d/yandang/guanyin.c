// Room: /d/yandang/guanyin
inherit ROOM;

void create ()
{
  set ("short", "������");
  set ("long", @LONG
������嶴,�����޺���.���ں��Ʒ���,����113��,��14��,���ҹ�
���Ų�¥��.Ϊ�㵴ɽ��һ����.��˵��ǰ�и���ɮ���Ծ��ڶ���,��ҹ��
'������'.������վ���ĵط����ǵ�һ����.
LONG);

  set("objects", ([ /* sizeof() == 1 */
//  __DIR__"npc/shami.c" : 1,
]));
  set("exits", ([ /* sizeof() == 2 */
  "out" : __DIR__"shanlu6",
  "up" : __DIR__"guanyin1",
]));

  setup();
}
int valid_leave(object me,string dir)
{
  object ob;
ob=present("qing ji",this_object());
 if (objectp(ob)&&dir=="up")     {
        if (ob->query("banghui")!=me->query("banghui"))
    return notify_fail("Сɳ������̨������ס��:�㲻���ұ����ֵܰ�!\n");
        }
 return ::valid_leave(me,dir);
}
      
