//room: /d/tanggu/zhahuopu.c

inherit ROOM;
void create()
{
        set("short", "�ӻ���");
        set("long", @LONG
����һ���ӻ��̣����ϵر��ĸ�ʽ������ﶼ�С���̨����Ļ�����ʰ��
�ǳ����롣�����ϰ岻�ڣ�С��ƶ���ǽ���ﲻ������
    ��ǰ���˸�����(sign)��
LONG );
        set("exits", ([
                "south" : __DIR__"stdongjie1",   	
	]));

	set("objects", ([
                __DIR__"npc/huoji" : 1,
      	]));

	setup();
}
