// caoyuan1.c ��ԭ
inherit ROOM;
void create()
{
        set("short", "��ԭ");
        set("long", @LONG
���߽���������಻���Ĵ��ԭ�������Ǵ�����ݣ�������Ļ�
�治���ߣ�������ƥ�����������ǵĺ����⡣���ߺ����߶��кö�����
�������Կ���ɳĮ�ı�Ե��
LONG);
        set("exits", ([
            "southeast" : __DIR__"caoyuan",
            "south" : __DIR__"caoyuan1",
            "northup" : __DIR__"caoyuan3",
        ]));
        set("outdoors", "dingxiang");

        setup();
        replace_program(ROOM);
}
