inherit ROOM;
void create()
{
        set("short", "˽�̷�");
        set("long", @LONG
������ǧ��¥����Ϊ潵ĵط���ÿ�����Ͼͷ��Ĺ��ﶼ�ᱻ������������Ժȡ�
�绹���ӣ������̿���ǽ�Ϻ͵��϶��а���ɫ��Ѫ�����ݽ�һ�Ű����С��������
���ҵĴ������ƺ���������ҧ���ĺۼ���
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"sr2",
]));
       set("objects", ([
        __DIR__"npc/funu" : 2,
	__DIR__"obj/broken_cloth" : 2,
                        ]) );


        set("coor/x",-120);
	set("coor/y",-10);
	set("coor/z",-10);
	setup();
        replace_program(ROOM);
}
