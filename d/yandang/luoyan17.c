// Room: /d/yandang/luoyan17.c

inherit ROOM;

void create()
{
	set("short", "��ʯ���");
	set("long", @LONG
����һ����ʯ���̳ɵĴ��,����ɽׯ��������,ÿ��Ľ��ǰ����
������ʿ���ﲻ��,·������ľɭɭ,����¥������,���ɾ���,�Ӵ˵���
��,���е��Ӿ���,������Ů���Ӿ���,���ǿͷ�.
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"luoyan34.c",
  "south" : __DIR__"luoyan19",
  "north" : __DIR__"luoyan18",
  "west" : __DIR__"luoyan9",
]));
	set("outdoors", "/d/yandang");
	set("no_clean_up", 0);

	setup();
}
int valid_leave(object me, string dir)
{
	object ob;
    if ((dir!="east")&&(dir!="west")&&(me->query("family/family_name")!="�㵴��")){
         return notify_fail("����ɽׯ���,ɽׯ���ӵķ��仹�ǲ�Ҫ������\n");
    }else{
	   if ( (dir=="south") && (me->query("gender")=="����") )
	        return notify_fail("ι,�ߴ���,�е��ӵ�ס���ڱ��棡\n");
	   else{
	        if((dir=="north")&&(me->query("gender")=="Ů��") )
	        return notify_fail("�㿴��һȺ�е�������˯��,��æ���˳���,�ߴ�����!\n");
       }   
	   return ::valid_leave(me, dir);
     }
}
