//jinling  wuqidian.c
inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
�����ǽ���ǵ������ꡣ���۸��ֱ�������û��ʲô�����������������
�ı���Ҳ�����ԳƵ���������������������ȫ���۸����У����ܽ������µ�
��ӭ��
LONG
        );
        set("exits", ([/* sizeof() == 4 */
           "west" : __DIR__"beijie2",

]));
        set("objects", ([
		__DIR__"npc/tiejiang" : 1,

			]) );

        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}