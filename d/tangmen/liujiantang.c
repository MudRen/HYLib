// Room: /dream/liujiantang.c
// HEM 1998/11/5
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "������");
	set("long", @LONG
	�������á�������˼�壬���������ŵķÿͣ��������Ҫ���±�����������
�����������š�
LONG
	);
        set("exits", ([
		"south" : __DIR__ "tianjing",
		"northwest" : __DIR__ "zhaobi",
                "northeast" : __DIR__ "zhaobi",
		"west" : __DIR__ "huayuan1",
		"east" : __DIR__ "huayuan6",
	]));
          set("valid_startroom", 1);
	set("objects", ([
                "/quest/menpaijob/tangmen/tang_wuhuo" : 1,
                __DIR__"npc/dizi" : 2,
        ]));

	setup();
//	replace_program(ROOM);
	"/clone/board/tangmen_b"->foo();

}
int valid_leave(object me, string dir)
{
    object *inv;
    mapping myfam;
    int i;
myfam = (mapping)me->query("family");
               

    if ((!myfam || myfam["family_name"] != "����" ) && dir == "west"  ) {
        inv = all_inventory(me);
        for(i=sizeof(inv)-1; i>=0; i--)
            if(inv[i]->query("weapon_prop") && (inv[i]->query("equipped")))
                if(objectp(present("tang wuhuo", environment(me))))
                    return notify_fail("���޻���ס��ȵ�����λ" +
                        RANK_D->query_respect(me) + "����±��С��ٽ�ȥ����"
                        "�������ã����\n���óֱ������ڣ�\n");
                
    }
    if ((!myfam || myfam["family_name"] != "����" ) && dir == "east"  ) {
        inv = all_inventory(me);
        for(i=sizeof(inv)-1; i>=0; i--)
            if(inv[i]->query("weapon_prop") && (inv[i]->query("equipped")))
                if(objectp(present("tang wuhuo", environment(me))))
                    return notify_fail("���޻���ס��ȵ�����λ" +
                        RANK_D->query_respect(me) + "����±��С��ٽ�ȥ����"
                        "�������ã����\n���óֱ������ڣ�\n");
                
    }
    if ((!myfam || myfam["family_name"] != "����" ) && dir == "south"  ) {
        inv = all_inventory(me);
        for(i=sizeof(inv)-1; i>=0; i--)
            if(inv[i]->query("weapon_prop") && (inv[i]->query("equipped")))
                if(objectp(present("tang wuhuo", environment(me))))
                    return notify_fail("���޻���ס��ȵ�����λ" +
                        RANK_D->query_respect(me) + "����±��С��ٽ�ȥ����"
                        "�������ã����\n���óֱ������ڣ�\n");
                
    }
    return ::valid_leave(me, dir);
}



