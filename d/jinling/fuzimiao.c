//jinling  fuzimiao��c
inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
Ϊ�����׳ƣ��ֳ������ǹ���ͼ�����ӵĵط�,���䡰��שС����ͷǽ��
���ȹ��仨�񴰡��Ľ���������һʱ������ѧ�����ﲻ�����޲���հ���¿��ӵ�
��ò��
LONG
        );
        set("exits", ([/* sizeof() == 4 */
           "east" : __DIR__"nanjie2",

]));
set("objects", ([
              __DIR__"npc/xuezi" : 1,
              __DIR__"npc/wulinren" : 1,
			]) );

 set("outdoors", "jinling");

        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}