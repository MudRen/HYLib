// jiangban.c
// bbb 1997/07/20
// Modify By River 98/12
inherit ROOM;

void create()
{
        set("short", "����");
	set("long", @LONG
���ŭ����ӿ��ˮ���ļ�������ɽʯ���������Ρ�룬�������ƣ����ǵ�
�����ֽ��ߣ������뽲����ʮ���ɸߣ���ˮ��Ȼ���ǣ�Ҳ�����͵��˴�����
ȫ��ɽʯ��
LONG
	);

	set("exits", ([
           "enter" : __DIR__"taijie",
           "down" : __DIR__"anbian1",
	]));
        set("outdoors", "����");
	setup();
}
