// Room: /city2/zhengmen.c

#include <room.h>

inherit ROOM;

string look_gaoshi();

void create()
{
	set("short", "�ʹ�����");
	set("long", @LONG
	����ǻʹ����š�Ρ����ΰ�ĳ�ǽ�ϣ�'�Ͻ���'��������ʮ�����ۣ�
���ƻԻ͡�һ�ŷ��Ƶĸ�ʾ(gaoshi)����ǽ�ϣ����ٱ��������ԡ�
LONG
	);

	set("item_desc", ([
		"gaoshi" : (:look_gaoshi:),
	]));

	set("exits", ([
		"south" : __DIR__"bridge",
	]));
        set("objects", ([
                __DIR__"/d/city/npc/wujiang" : 1,
                __DIR__"/d/city/npc/bing" : 2,
        ]));
	set("outdoors", "city2");
	setup();
}

string look_gaoshi()
{
	return "������ػ�һ�ڷ���! \n�ٱ�һ�ˣ��ͽ�ʮ��;\n"
          "׽��һ�ˣ��ͽ������\n֪�鲻���ߣ���ն!\n���ݷ�\n";
}

int valid_leave(object me, string dir)
{
    int i;
    object *inv;
    if(dir=="north")
    {
     if( this_player()->query_temp("canenter") )
        {
        inv = all_inventory(me);
        for(i=sizeof(inv)-1; i>=0; i--)
            if(inv[i]->query("weapon_prop") && (inv[i]->query("equipped")))
                if(objectp(present("wujiang", environment(me))))
                    return notify_fail("�佫��ס��˵������λ" +
                        RANK_D->query_respect(me) + "����±��С�"
                        "���óֱ����빬��\n");
                else if(objectp(present("bing", environment(me))))
                    return notify_fail("�ٱ���ס��˵������λ" +
                        RANK_D->query_respect(me) + "����±��С�"
                        "���óֱ����빬��\n");
     }               				
     else
     {
     if (me->query("gender") == "Ů��") {
        if(objectp(present("wujiang", environment(me))))
            return notify_fail("�佫������ס������˵�����ʹ��صأ���" 
            "��Ѱ���̻�Ů�����ɳ���," + RANK_D->query_respect(me) +"\n��أ����"
                "��ȡ���衣\n");
        else if(objectp(present("bing", environment(me))))
            return notify_fail("�ٱ�������ס������˵�����ʹ��صأ���" 
            "��Ѱ���̻�Ů�����ɳ���," + RANK_D->query_respect(me) +"\n��أ����"
            "��ȡ���衣\n");
    }
     if (me->query("gender") == "����") {
        if(objectp(present("wujiang", environment(me))))
            say("�佫Ц������˵������λ�����������ˣ�������ɡ�\n");
        else if(objectp(present("bing", environment(me))))
            say("�ٱ�Ц������˵������λ�����������ˣ�������ɡ�\n");
    }
   return ::valid_leave(me, dir);
}
