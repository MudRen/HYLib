// Room in ����
inherit ROOM;
void create()	
{
	set("short", "����");
	set("long", @LONG
�����ǴӸ��������ıؾ�֮�أ��������ϴ�����ֱ�ӵ������ݡ���
��ǳ����֣�ͣ���Ÿ��ִ�ֻ���л������̴��ȵȡ��ܶ��ÿʹ������
���ۿڣ��д���ԭ���ģ�Ҳ�д������ط����ġ����С�������������
LONG
	);
set("outdoors", "/d/gaoli");
set("exits", ([
                "west" : __DIR__"yucun",
	]));
       setup();
	replace_program(ROOM);
}	
