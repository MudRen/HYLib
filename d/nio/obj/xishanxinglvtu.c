// /u/jpei/thd/obj/xishanxinglvtu.c

inherit ITEM;

void create()
{
        set_name("Ϫɽ����ͼ", ({ "painting", "xi shan xing lv tu", "tu" }) );
	set("long", "���Ǿ�˵�Ѿ�ʧ���˵ķ����漣�����ڰ���֮�ˣ������޼�֮���ˡ�\n");
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("no_get", "�����޼�֮�����Է���˯�������ڻ���ģ�\n");
                set("no_drop", "������޼�֮��������ô�ϴ�һ���ˣ���Ȼ��˲�ʶ������\n");
		set("value", 1000000);
	        set_weight(20);
//		set("treasure", 1);
        }
        setup();
}

