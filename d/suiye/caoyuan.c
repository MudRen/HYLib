// caoyuan.c ��ԭ
inherit ROOM;
void create()
{
        set("short", "��ԭ��Ե");
        set("long", @LONG
�����Ǵ��ԭ��ɳĮ����֮�أ������ϡ���ܣ��������������ȥ��
�����м�������̤������ӡ�����������ﳣ�����̶����������Ϸ�������
Щ���̡�
LONG);
        set("exits", ([
            "north" : "/d/dingxiang/xiaolu3",
            "southwest" : __DIR__"dadao2",
            "south" : "/d/jyguan/luzhou",
        
        ]));
        set("outdoors", "suiye");
        setup();
}
