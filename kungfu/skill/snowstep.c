// snowstep.c ÷ѩƮ�㲽

inherit SKILL;
#include <ansi.h>

string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});

string *dodge_msg = ({
	"$nһʽ"+(order[random(13)])+"������ѩ�ڡ�"NOR"��һ�»������⿪ȥ����$N���ƻ�����Ρ�\n",
	"$nʹ��"+(order[random(13)])+"����ʨ���衹"NOR"��һ�����$Nͷ��һ��������$N��$n���š�\n",
	"$n�Ų���ȣ�������ң�ʹ��"+(order[random(13)])+"��ѩ��ƺӡ�"NOR"��$N��Ҹ�´���$P���ᡣ\n",
	"$n΢Ц����������������һ�٣�һʽ"+(order[random(13)])+"����ѩ���Ρ�"NOR"���$N��һ����\n",
	"$n��ת���ӣ�����һԾ��һʽ"+(order[random(13)])+"��ʨ��ҡͷ��"NOR"���赭д�ػ���$N��һ�С�\n",
	"$n��������һ�ݣ�ʹ��һʽ"+(order[random(13)])+"��̤ѩ�޺ۡ�"NOR"Ծ�����ߣ�ƮȻ�䵽һ�ԡ�\n",
    "����$n��Цһ��,����߲�����,һʽ"+(order[random(13)])+"����÷Ʈѩ��"NOR",�������������С�\n",
    "$n����ת��,һ��"+(order[random(13)])+"��̴����ס�"NOR",�����ְ�Ʈ�����,�ܹ������С�\n",
    "ֻ��$n����һ��,�������,ʹ��"+(order[random(13)])+"��÷�»ƻ衹"NOR",�����˶�ʧȥ����Ӱ,��$N���˸��ա�\n",
    "ȴ��$n����������ңңһ��,һʽ"+(order[random(13)])+"��÷Ʈ������"NOR",������������Ʈ��,��������С�\n",
    "$n��Цһ��,һʽ"+(order[random(13)])+"����÷��ѩ��"NOR",�������,һʱ����˷�����$n��Ӱ��,����ʵʵ,��֪�ĸ�������ġ�\n"
});

int valid_enable(string usage)
{
    return (usage=="dodge");
}

int valid_learn(object me)
{
    return 1;
}

string query_dodge_msg(string limb)
{
    return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
    if( (int)me->query("qi") < 30 )
   return notify_fail("�������̫���ˣ�������÷ѩƮ�㲽......\n");
    me->receive_damage("qi", 10);
    return 1;
}

string perform_action_file(string action)
{
        return __DIR__"snowstep/" + action;
}
