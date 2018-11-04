// Room: /city/wudao2.c
// Date: Feb 27.1998 by Java
#include <ansi.h>;
inherit ROOM;
string look_gaoshi();
void create()
{
	set("short", "�ĺ���");
	set("long", @LONG
�������ĺ���̨����ҿ��ڴ���������������ս������ "���ŵ�һ" ��
�ƺš�̨�ϸ�ʾ(gaoshi)��������λ��������Ҫ��һ�£�������ʦ��ᡣ����
�ʹ����������������񣬶�������Ƹ�����������ǰ������Ҷ���һ������
���мӵġ�
LONG );
        set("outdoors", "city");
	set("item_desc", ([
		"gaoshi" : (: look_gaoshi :),
	]));

	set("exits", ([
		"east" : __DIR__"wudao",
	]));
        set("objects", ([
                __DIR__"npc/gulong" : 1,
        ]));
	set("no_clean_up", 0);
	setup();
}
string look_gaoshi()
{
	return 
"
1. ����̨�㵽Ϊֹ��ֻ��ʤ�ܣ�����������
2. ����̨�ɵ�ֵ��ʦ���Ÿ�����˳�α��䡣ԭ����������������������ȡ�
3. �ڱ����У���������Ǳ������ɵ��ӽ�����̨����ʦ��Ȩ���κα�Ҫ��ʽά
   ����������˳�����С�
4. ������ҲӦ�ȵ���������ʵ����������ȥ���Ź����ν�û��·�ѡ�
5. ����ʹ�����������书������perform��powerup��enforce��poison �ȡ�
6. ����ʹ�ó���˿�ף���⫼ף���˿����������з��ߡ�
7. ������ʹ�ù���������50�ı����簽��ذ�ף����콣����ħ���ȣ���������
   �����ڴ��ޡ�
8. Υ��6.7 ��������ʵ�������ȡ���ƺ��⣬׷���ط���
9. ÿ�����ɵó�ǰ��������߽�Ʒ��������ѡȡ��

                                    �ĺ���̨  ����\n";
}
void init()
{
	add_action("do_quit","quit");
	add_action("do_quit","exit");
	add_action("do_quit","practice");
	add_action("do_quit","lian");
	add_action("do_quit","study");
	add_action("do_quit","du");
}

int do_quit(string arg)
{
        write(this_player()->query("name")+"��ר�Ŀ�����ɣ�\n");
	return 1;
}
int valid_leave(object me, string dir)
{
	object obj;
	if (objectp(obj = present("gu long", environment(me))))
		if (obj->query("candidate")->query("id") == me->query("id"))
		return notify_fail("������ס��˵�����Ǻ�ѡ�ˣ�������ϯ֮��\n");

        return ::valid_leave(me, dir);
}
