//jinling  ximen.c
inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
�����ǽ�������ţ��߸ߵĳ�ǽ������ż������ģ����ſ�վ�ż���ֵ
�ڵĹٱ����㳯��������һ�ۣ�����һ���ٱ�����ض�����һ�ۣ��㲻����
�˸����£����ǿ���߰ɡ�
LONG
        );
        set("exits", ([/* sizeof() == 4 */
       "west" : __DIR__"guanroad2",
   "east" : __DIR__"xijie2",


]));
         set("objects", ([
           __DIR__"npc/bing" : 3,
			]) );
 set("outdoors", "jinling");
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}
