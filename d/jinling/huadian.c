//jinling  huadian.c
inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
�����ǽ������Ψһ��һ�һ��꣬������ɫ��ȫ��Ʒ�ַ��࣬���ҿ�
�Բ�Զǧ�Ϊ���ͻ����š������������һ�����ϸ����ʻ������Ϻõ�
��Ʒ������һ��۸�ϸߣ���Ҫ����Ϊ���������������Ʒ��
LONG
        );
        set("exits", ([/* sizeof() == 4 */
           "east":__DIR__"nanjie1",

]));
        set("objects", ([
		__DIR__"npc/roseseller" : 1,
             __DIR__"npc/girl" : 1,
]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}