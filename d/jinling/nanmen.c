//yangzhou  nanmen.c
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
          "north" : __DIR__"nanjie2",
          "south" : "/d/jiangling/tulu",	//goto taohua
//          "south" : "/u/xiaoyao/...",	//goto xiaoyao


]));
 set("outdoors", "jinling"); 
        set("objects", ([
              __DIR__"npc/bing" : 3,
			]) );


        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}