// skybook.c

#include <ansi.h>

inherit ITEM;
inherit F_AUTOLOAD;


void create()
{
        set_name(HIY"��������"NOR, ({"skybook","book"}) );
        set_weight(10);
        set("no_steal", 1);
        set("no_beg", 1);
        set("no_get", 1);
        set("no_drop","�ۣ����鶼�붪��,С������Ǵ��\n\n");
        set("long",@LONG
���˵�����������"����"�ı���,��Ϊ������ʶ��,����ʩ�˷�,
������������������,�Ǻ�!������äҲ�ܶ���,�쿴��(kan)�ɣ�
LONG );
        if( clonep() )
                        set_default_object(__FILE__);
        else
       {
                set("treasure",1);set("unit", "��");
                set("material", "unknow");
        }
}

